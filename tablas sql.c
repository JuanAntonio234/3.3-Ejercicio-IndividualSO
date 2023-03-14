#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
//Conector para acceder al servidor de bases de datos
MYSQL *conn;
int err;
MYSQL_RES*resultado;
MYSQL_ROW row;

char ID[10];
char nombre[50];
char password[15];
int partidas_ganadas;
int partidas_perdidas;
char consulta[80];

//creamos una conexion al servidor

conn= mysql_init(NULL);
if(conn==NULL){
	printf ("Error al crear la conexion: %u %s\n", 
			mysql_errno(conn), mysql_error(conn));
	exit (1);
}
//inicializar la conexion, indicando nuestras claves de acceso
// al servidor de bases de datos (user,pass)
conn = mysql_real_connect (conn, "localhost","root", "mysql", NULL, 0, NULL, 0);
if (conn==NULL)
{
	printf ("Error al inicializar la conexion: %u %s\n", 
			mysql_errno(conn), mysql_error(conn));
	exit (1);
}

//consulta para obtener todos los datos de la tabla jugadores

err=mysql_query(conn, "SELECT * FROM JUGADOR");
if(err!=0){
	printf("Error al consultar los datos de la base %u%s\n",
		   mysql_errno(conn),mysql_error(conn));
	exit(1);
}
resultado=mysql_store_result(conn);

row =mysql_fetch_row(resultado);
if(row==NULL)
	printf ("No se han obtenido datos\n");
else 
	while(row!=NULL){
			partidas_ganadas=atoi(row[3]);
			partidas_perdidas=atoi(row[4]);
			
			printf("ID: %s,Nombre: %s,Password:%s, paridas_ganadas&d,partidas_perdidas%d\n", row[0],row[1],row[2]);
			
			//obtenemos la siguiente fila
			row=mysql_fetch_row(resultado);
}
	
//Consulta para ver los nombres de las personas que tienen menos partidas perdidas que las introducidas por consola
	printf ("Dame el número de partidas perdidas\n");
	scanf("%d",partidas_perdidas);
	strcpy(consulta,"SELECT nombre* FROM JUGADOR WHERE partidas_perdidas<'");
	strcat(consulta,partidas_perdidas);
	strcat(consulta,"'");
	err=mysql_query(conn,consulta);
	
	if(err!=0){
		printf("Error al consultar los datos de la base %u%s\n",
			   mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	resultado=mysql_store_result(conn);
	
	row =mysql_fetch_row(resultado);
	if(row==NULL)
		printf ("No se han obtenido datos\n");
	else 
		while(row!=NULL){
		partidas_ganadas=atoi(row[3]);
		partidas_perdidas=atoi(row[4]);
		
		printf("Nombre de las personas con menos de %d partidas perdidas:%s\n",partidas_perdidas, row[0]);
		
		//obtenemos la siguiente fila
		row=mysql_fetch_row(resultado);
	}
		//cerrar la conexion 
		mysql_close(conn);
		exit(0);
}


