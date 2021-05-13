/*
Pacial 1 - Laboratorio de programacion
Costanza, Lucas
Division 1B
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayTrabajos.h"
#define T 5
#define TS 4
#define LIBRE 0
#define OCUPADO 1

//Declaracion

int main(void) {
	setbuf(stdout, NULL);
	eTrabajo listaTrabajo[T];
	eServicio listaServicio[TS]={{20000, "Limpieza", 250, OCUPADO},
								{20001, "Parche", 300, OCUPADO},
								{20002, "Centrado", 400, OCUPADO},
								{20003, "Cadena", 350, OCUPADO}};
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
				"5.Listado de servicios\n"
				"6.Listar servicios y trabajos\n"
				"7.Precio total\n"
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
				if(modificarTrabajo(listaTrabajo, T, listaServicio, TS)!=-1)
				{
					printf("Trabajo modificado con exito!\n");
				}
				else
				{
					printf("Se cancelo la modificacion del trabajo!\n");
				}
				system("pause");
			break;

			case 3:
				if(bajaTrabajo(listaTrabajo, T)!=-1)
				{
					printf("Trabajo dado de baja con exito!\n");
				}
				else
				{
					printf("Se cancelo la baja del trabajo!\n");
				}
				system("pause");
			break;

			case 4:
				if(mostrarListadoTrabajos(listaTrabajo, T)!=-1)
				{
					printf("Listado de trabajos ordenados por año!\n");
				}
				else
				{
					printf("No hay trabajos que mostrar!\n");
				}
				system("pause");
			break;

			case 5:
				if(listadoServicios(listaServicio, TS)!=-1)
				{
					printf("Lista de servicios!\n");
				}
				else
				{
					printf("No hay servicios disponibles para mostrar!\n");
				}
				system("pause");
			break;

			case 6:
				if(listadoTrabajosYServicios(listaTrabajo, T, listaServicio, TS)!=-1)
				{
					printf("\nListado de trabajos con sus servicios!\n");
				}
				else
				{
					printf("No hay trabajos y servicios para mostrar!\n");
				}
				system("pause");
			break;
		}
		system("cls");
	}while(menu!=0);

	return EXIT_SUCCESS;
}
