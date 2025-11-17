#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "BOOKS.h"
using namespace std;

int main(int argc, char *argv[]) {

	int Menu;
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
		if (bookCount < MAX) {
			LogData(&stock[bookCount]);
			bookCount++;
		} else {
			printf("Stock lleno\n");
		}
		printf (" \n");
		printf("Datos cargados\n");
		break;
	case 2:
		printf("Tabla de datos de los libros:\n");
		////tableformat();
		for (int j = 0; j < bookCount; j++) {
			ShowData(stock, j);
		}
		printf (" \n");
		printf("Datos mostrados correctamente \n");
		break;
	case 3:
		SearchData(stock);
		printf (" \n");
		printf("Búsqueda realizada \n");
		break;
	case 4:
		printf ("Ha seleccionado guardar lista    \n");
		SaveToFileData(stock ,bookCount);
		break;
	case 5:
		printf ("Ha seleccionado cargar lista     \n");
		LoadFromFileData(stock ,bookCount);
		break;
	case 6:
		printf ("Usted ha elegido cerrar el programa, hasta luego.\n");
		GoodBye();
		break;
	}
	}while (Menu != 6);
	
	return 0;
}


