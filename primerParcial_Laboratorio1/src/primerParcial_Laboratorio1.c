/*

 */

#include <stdio.h>
#include <stdlib.h>
#define T 4
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idServicio;
	char descripcionServicio[26];
	float precioServicio;
}eServicio;

typedef struct
{
	int idTrabajo;
	char marcaBicicleta[21];
	int rodadoBicicleta;
	int idServicio;

	eFecha fechaTrabajo;

	int isEmpty;
}eTrabajo;

//Declaracion
eTrabajo pedirDatosTrabajo();
void inicializarTrabajo(eTrabajo listaTrabajo[], int tam);
void mostrarUnTrabajo(eTrabajo);
int mostrarListadoTrabajos(eTrabajo listaTrabajo[], int tam);
int altaTrabajo(eTrabajo listaTrabajo[], int tam, int *idTrabajo);
int buscarTrabajoLibre(eTrabajo listaTrabajo[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	eTrabajo listaTrabajo[T];
	eServicio listaServicio[4]={{"Limpieza", 250},
								{"Parche", 300},
								{"Centrado", 400},
								{"Cadena", 350}};
	int menu;
	int res;
	int *idTrabajo=0;
	inicializarTrabajo(listaTrabajo, T);

	do
	{
		printf("-- ABM TRABAJOS BICICLETA --\n"
				"1.Alta trabajo\n"
				"2.Modificar trabajo\n"
				"3.Baja trabajo\n"
				"4.Listado de trabajo\n"
				"5.Listar servicios\n"
				"6.Precio total\n"
				"Seleccione una opcion: ");
		scanf("%d", &menu);
		system("cls");
		switch(menu)
		{
			case 1:
				res=altaTrabajo(listaTrabajo, T, &idTrabajo);
				if(res!=-1)
				{
					printf("Trabajo dado de alta exitosamente!\n");
				}
				else
				{
					printf("No hay mas espacio para listar trabajo!\n");
				}
				system("Pause");
			break;

			case 2:

			break;

			case 3:

			break;

			case 4:

			break;

			case 5:
				//Funcion mostrar para testear, en un futuro ordenara
				if(mostrarListadoTrabajos(listaTrabajo, T)!=-1)
				{
					printf("Listado de trabajos!\n");
				}
				else
				{
					printf("No hay trabajos que mostrar!\n");
				}
				system("pause");
			break;
		}
		system("cls");
	}while(menu!=0);

	return EXIT_SUCCESS;
}

void inicializarTrabajo(eTrabajo listaTrabajo[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaTrabajo[i].isEmpty=LIBRE;
	}
}

eTrabajo pedirDatosTrabajo()
{
	eTrabajo miTrabajo;

	printf("Ingrese la marca de la bicicleta: ");
	scanf("%s", &miTrabajo.marcaBicicleta);

	utn_getNumero(&miTrabajo.rodadoBicicleta, "Ingrese el rodado de su bicicleta: ", "Error, rodado incorrecto\n", 1, 29, 4);

	utn_getNumero(&miTrabajo.idServicio, "Ingrese el ID de su servicio: ", "Error, ID incorrecto", 20000, 20020, 4);

	utn_getNumero(&miTrabajo.fechaTrabajo.dia, "Ingrese el dia del servicio: ", "Error, dia incorrecto", 1, 31, 4);

	utn_getNumero(&miTrabajo.fechaTrabajo.mes, "Ingrese el mes del servicio: ", "Error, mes incorrecto", 1, 12, 4);

	utn_getNumero(&miTrabajo.fechaTrabajo.anio, "Ingrese el anio del servicio: ", "Error, anio incorrecto", 2010, 2021, 4);

	miTrabajo.isEmpty=OCUPADO;

	return miTrabajo;
}

int altaTrabajo(eTrabajo listaTrabajo[], int tam, int *idTrabajo)
{
	int i;
	i=buscarTrabajoLibre(listaTrabajo, tam);

	if(i!=-1)
	{
		listaTrabajo[i]=pedirDatosTrabajo();
		listaTrabajo[i].idTrabajo=*idTrabajo+1;
		*idTrabajo=listaTrabajo->idTrabajo;
	}

	return i;
}

int buscarTrabajoLibre(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int retorno;

	for(i=0; i<tam; i++)
	{
		if(listaTrabajo[i].isEmpty==LIBRE)
		{
			retorno=i;
			break;
		}
	}

	return retorno;
}

void mostrarUnTrabajo(eTrabajo unTrabajo)
{
	printf("%d %s %d %d %d %d %d \n",
			unTrabajo.idTrabajo,
			unTrabajo.marcaBicicleta,
			unTrabajo.rodadoBicicleta,
			unTrabajo.idServicio,
			unTrabajo.fechaTrabajo.dia,
			unTrabajo.fechaTrabajo.mes,
			unTrabajo.fechaTrabajo.anio);
}

int mostrarListadoTrabajos(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int retorno=-1;

	for(i=0; i<tam; i++)
	{
		if(listaTrabajo[i].isEmpty==OCUPADO)
		{
			mostrarUnTrabajo(listaTrabajo[i]);
			retorno=0;
		}
	}

	return retorno;
}
