#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "BOOKS.h"
using namespace std;

int main(int argc, char *argv[]) {

	int Menu; //menu de seleccion de logica del programa
	do {
	printf (" \n");
	printf ("_______________________________________________________________________________________________ \n");
	printf ("Bienvenido al menú de control de stock de libros, elija una opción para continuar \n");
	printf ("1) Añadir un libro a la lista \n");
	printf ("2) Mostrar inventario de libros \n");
	printf ("3) Buscar libros por sus parámetros \n");
	printf ("4) Guardar lista actual \n");
	printf ("5) Cargar lista de archivo \n");
	printf ("6) Cerrar programa \n");
	printf ("\n SU OPCION: ---->   ");
	scanf ("%d",&Menu);
	fflush(stdin);
	
	switch(Menu){
	case 1:
		if (bookCount < MAX) { //comprobamos que el stock de datos guardados no exceda el MAX definido en BOOK.h
			LogData(&stock[bookCount]); //llamada a LogData en BOOKS_H.
			bookCount++;
		} else {
			printf("Stock lleno, no se cargaran datos\n"); //Si la cuenta de libros guardados es mayor al stock hacemos print de este mensaje
			break;
		}
		printf (" \n");
		printf("Datos cargados\n"); //si aun hay espacio se cargaran datos por la funcion LogData y anunciaremos la carga con este print<<
		break;
	case 2:
		printf("Tabla de datos de los libros:\n");
		for (int j = 0; j < bookCount; j++) {
			ShowData(stock, j); //llamada a ShowData en BOOKS_H.
		}
		printf (" \n");
		printf("Datos mostrados correctamente \n");
		break;
	case 3:
		SearchData(stock); //llamada a SearchData en BOOKS_H.
		printf (" \n");
		printf("Búsqueda realizada \n");
		break;
	case 4:
		printf ("Ha seleccionado guardar lista    \n");
		SaveToFileData(stock ,bookCount);  //llamada a SaveToFileData en BOOKS_H.
		break;
	case 5:
		printf ("Ha seleccionado cargar lista     \n");
		LoadFromFileData(stock ,bookCount);  //llamada a LoadFromFileData en BOOKS_H.
		break;
	case 6:
		printf ("Usted ha elegido cerrar el programa, hasta luego.\n");
		GoodBye();  //llamada a GoodBye en BOOKS_H.
		break;
	}
	}while (Menu != 6);
	
	return 0;
}


