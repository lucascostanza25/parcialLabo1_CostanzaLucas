/*
 * arrayTrabajos.c
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayTrabajos.h"
#define T 5
#define TS 4
#define LIBRE 0
#define OCUPADO 1

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
			ordenarTrabajos(listaTrabajo, tam);
			mostrarUnTrabajo(listaTrabajo[i]);
			retorno=0;
		}
	}

	return retorno;
}

int modificarTrabajo(eTrabajo listaTrabajo[], int tam, eServicio listaServicio[], int tamServicio)
{
	int i;
	int j;
	int retorno=-1;
	int idIngresado;
	int eleccion;

	if(listaTrabajo->isEmpty==OCUPADO)
	{
		printf("Trabajos disponibles para modificar!\n");
		mostrarListadoTrabajos(listaTrabajo, tam);
		utn_getNumero(&idIngresado, "Ingrese el ID del trabajo a modificar: ", "Error, ID incorrecto\n", 1, 10, 4);
		for(i=0; i<tam; i++)
		{
			for(j=0; j<tamServicio; j++)
			{
				if(idIngresado==listaTrabajo[i].idTrabajo && listaTrabajo[i].idServicio==listaServicio[j].idServicio)
				{
					printf("-- MODIFICAR --\n"
							"1.Marca\n"
							"2.Servicio\n"
							"Seleccione una opcion: ");
					scanf("%d", &eleccion);
					system("cls");
					switch(eleccion)
					{
						case 1:
							printf("Ingrese la marca de la bicicleta: ");
							scanf("%s", &listaTrabajo[i].marcaBicicleta);
						break;

						case 2:
							printf("Ingrese la descripcion del servicio: ");
							scanf("%s", &listaServicio[j].descripcionServicio);
						break;

					}
					retorno=0;
				}

			}
		}
	}
	else
	{
		printf("No hay trabajos disponibles para editar!\n");
	}


	return retorno;
}

int bajaTrabajo(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int retorno=-1;
	int idIngresado;

	if(listaTrabajo->isEmpty==OCUPADO)
	{
		printf("Trabajos disponibles para dar de baja!\n");
		mostrarListadoTrabajos(listaTrabajo, tam);
		utn_getNumero(&idIngresado, "Ingrese el ID del trabajo a modificar: ", "Error, ID incorrecto\n", 1, 10, 4);
		for(i=0; i<tam; i++)
		{
			if(idIngresado==listaTrabajo[i].idTrabajo)
			{
				listaTrabajo[i].isEmpty=LIBRE;
				retorno=0;
				break;
			}
		}
	}
	else
	{
		printf("No hay trabajos disponibles para dar de baja!\n");
	}

	return retorno;
}

void ordenarTrabajos(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int j;
	eTrabajo auxTrabajo;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(listaTrabajo[i].fechaTrabajo.anio < listaTrabajo[j].fechaTrabajo.anio)
			{
				auxTrabajo=listaTrabajo[i];
				listaTrabajo[i]=listaTrabajo[j];
				listaTrabajo[j]=auxTrabajo;
			}
		}
	}
}

int listadoTrabajosYServicios(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio)
{
	int i;
	int j;
	int retorno=-1;

	for(i=0; i<tamTrabajo; i++)
	{
		for(j=0; j<tamServicio; j++)
		{
			if(listaTrabajo[i].idServicio==listaServicios[j].idServicio)
			{
				printf("%d %s %d %d %s %f\n",
						listaTrabajo[i].idTrabajo,
						listaTrabajo[i].marcaBicicleta,
						listaTrabajo[i].rodadoBicicleta,
						listaTrabajo[i].idServicio,
						listaServicios[j].descripcionServicio,
						listaServicios[j].precioServicio);
				retorno=0;
			}
		}
	}

	return retorno;
}

int listadoServicios(eServicio listaServicios[], int tam)
{
	int i;
	int retorno=-1;

	for(i=0; i<tam; i++)
	{
		printf("%d %s %f\n",
				listaServicios[i].idServicio,
				listaServicios[i].descripcionServicio,
				listaServicios[i].precioServicio);
		retorno=0;
	}

	return retorno;
}
