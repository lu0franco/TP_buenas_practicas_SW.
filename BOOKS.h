#ifndef BOOKS_H
#define BOOKS_H

#define MAX 20
struct book{
	char Title [100];
	char Writer [50];
	int PublishYear;
} stock [MAX];
int bookCount = 0;
void LogData(book* m);
void ShowData(book* m , int i);
void SearchData(book* m);
void GoodBye();
void tableformat();
void SaveToFileData(book* m , int Cantbooks);
void LoadFromFileData(book* m , int Cantbooks);
void LogData(book* m) {
	char buffer[100];
	
	printf("Ingrese el Titulo del libro: ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%21[^\n]", m->Title);  // Máximo 19 caracteres
	
	// Marca (Writer)
	printf("Ingrese el autor: ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = 0;  // Eliminar '\n'
	strncpy(m->Writer, buffer, sizeof(m->Writer) - 1);
	m->Writer[sizeof(m->Writer) - 1] = '\0';
	
	// Corriente: positivo
	int flagPublishYear;
	
	do {
		printf("Ingrese el año de publicación, NOTA: solo se admiten valores positivos --> ");
		fgets(buffer, sizeof(buffer), stdin);
		
		// Intentar convertir a float y validar que sea positivo
		if (sscanf(buffer, "%d", &flagPublishYear) == 1 && flagPublishYear >= 0) {
			m->PublishYear = flagPublishYear;
			break;
		} else {
			printf("Entrada inválida. Intente de nuevo.\n");
		}
		
	} while (1);
	
}

void ShowData(book* m , int i) {
	printf("%d)\n",i);
	printf("Título: %s\n",m[i].Title);
	printf("Escritor: %s\n",m[i].Writer);
	printf("Año del publicación: %d\n",m[i].PublishYear);
	printf("______________________________\n");
	
}

void SearchData(book* m) {
	
	fflush(stdin);
	int Menuaux;
	do {
		printf("Ingrese parámetro a buscar: \n");
		printf ("1) buscar por Título \n");
		printf ("2) buscar por Escritor \n");
		printf ("3) Buscar año de publicación \n");
		printf ("\n SU OPCION: ---->   ");
		scanf ("%d",&Menuaux);
		switch(Menuaux){
		case 1:
			char TitleSearch[100];
			printf("Ingrese titulo a buscar-->");
			scanf("%s", TitleSearch);
			for (int i = 0; i < bookCount; i++) {
				if (strcmp(m[i].Title, TitleSearch) == 0) {
					//tableformat();
					ShowData(m, i);
					return;
				}
			}
			printf("No se han encontrado coincidencias.\n");
			break;
		case 2:
			char WriterSearch[50];
			printf("Ingrese autor a buscar-->");
			scanf("%s", WriterSearch);
			for (int i = 0; i < bookCount; i++) {
				if (strcmp(m[i].Writer, WriterSearch) == 0) {
					//tableformat();
					ShowData(m, i);
					return;
				}
			}
			printf("No se han encontrado coincidencias.\n");
			break;
		case 3:
			int YearPublishSearch;
			printf("Ingrese año de publicación a buscar-->");
			scanf("%d", &YearPublishSearch);
			for (int i = 0; i < bookCount; i++) {
				if (m[i].PublishYear == YearPublishSearch) {
					//tableformat();
					ShowData(m, i);
					return;
				}
			}
			printf("No se han encontrado coincidencias.\n");
			break;
			break;
		}
	}while (Menuaux != 3);
	
}

void GoodBye() {
	
	printf(" _____  _________________  ___   _   _______ _____        _____ _____ _____ _____ ________  ___  ___   _____ \n");
	printf("/  __ \\|  ___| ___ \\ ___ \\/ _ \\ | \\ | |  _  \\  _  |      /  ___|_   _/  ___|_   _|  ___|  \\/  | / _ \\ /  ___|\n");
	printf("| /  \\/| |__ | |_/ / |_/ / /_\\ \\|  \\| | | | | | | |      \\ `--.  | | \\ `--.  | | | |__ | .  . |/ /_\\ \\\\ `--. \n");
	printf("| |    |  __||    /|    /|  _  || . ` | | | | | | |       `--. \\ | |  `--. \\ | | |  __|| |\\/| ||  _  | `--. \\\n");
	printf("| \\__/\\| |___| |\\ \\| |\\ \\| | | || |\\  | |/ /\\ \\_/ /      /\\__/ /_| |_\\/__/ / | | | |___| |  | || | | |/\\__/ /\n");
	printf(" \\____/\\____/\\_| \\_\\_| \\_\\_| |_\\/| \\_/___/  \\___/       \\____/ \\___/\\____/  \\_/ \\____/\\_|  |_\\/\\_| |_\\/\\____/ \n");
	printf("                                                                                                       \n");
	printf("EL PROGRAMA SE FINALIZO\n");
	return;
}
void SaveToFileData(book* m , int Cantbooks) {
	//int i=-1;
	char nameFile[15]="SavedList";
	strcat(nameFile, ".bin");
	FILE  *Filebin;
	
	/*Uso de fprintf*/
	Filebin = fopen(nameFile,"wb");
	if (Filebin != NULL) {
		fwrite(&Cantbooks, sizeof(int), 1, Filebin); // Guardar cantidad primero
		fwrite(m, sizeof(book), Cantbooks, Filebin);
		fclose(Filebin);
		printf("Se ha terminado de escribir %s \n", nameFile);
	} else printf("Problemas al abrir el archivo.");
	
	
	return;
}
void LoadFromFileData(book* m , int CantbookesParam) {
	char nameFile[20] = "SavedList.bin";
	FILE *Filebin = fopen(nameFile, "rb");
	if (Filebin != NULL) {
		int cantidad;
		fread(&cantidad, sizeof(int), 1, Filebin); // Leemos la cantidad real
		if (cantidad > MAX) {
			printf("Archivo contiene más libros de los que permite el programa.\n");
			fclose(Filebin);
			return;
		}
		//size_t leidos = fread(m, sizeof(book), cantidad, Filebin);
		fread(m, sizeof(book), cantidad, Filebin);
		bookCount = cantidad;  // ¡¡¡ACTUALIZAMOS bookCount!!!
		fclose(Filebin);
		printf("Se han leído %d libros desde %s\n", bookCount, nameFile);
	} else {
		printf("Problemas al abrir el archivo para leer.\n");
	}
}
#endif // BOOKS_H
