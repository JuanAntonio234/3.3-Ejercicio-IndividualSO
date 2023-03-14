DROP DATABASE IF EXISTS bd;
CREATE DATABASE bd;
USE bd;
CREATE TABLE JUGADOR(
ID VARCHAR(10) NOT NULL,
NOMBRE VARCHAR(50),
PASSWORD VARCHAR(15) NOT NULL,
INT PARTIDAS_GANADAS,
INT PARTIDAS_PERDIDAS,
PRIMARY KEY(ID)
)ENGINE=Inno DB;

CREATE TABLE PARTIDA(
JUGADORES INT NOT NULL,
DURACION INT,
GANADOR VARCHAR(50),
FECHA VARCHAR(20),
ID NOT NULL,
PRIMARY KEY(ID)
)ENGINE = InnoDB;


INSERT INTO JUGADOR VALUES("123S","Manuel","12D",5,7);
INSERT INTO JUGADOR VALUES("783P","José","85f",10,3);
INSERT INTO JUGADOR VALUES("756J","María","8e9",8,10);
INSERT INTO JUGADOR VALUES("859W","Marta","12gh",2,14);
