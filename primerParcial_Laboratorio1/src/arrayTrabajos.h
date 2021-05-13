/*
 * arrayTrabajos.h
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */

#ifndef ARRAYTRABAJOS_H_
#define ARRAYTRABAJOS_H_

#define T 5
#define TS 4
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

	int isEmpty;
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

eTrabajo pedirDatosTrabajo();
void inicializarTrabajo(eTrabajo listaTrabajo[], int tam);
void mostrarUnTrabajo(eTrabajo);
int mostrarListadoTrabajos(eTrabajo listaTrabajo[], int tam);
int altaTrabajo(eTrabajo listaTrabajo[], int tam, int *idTrabajo);
int buscarTrabajoLibre(eTrabajo listaTrabajo[], int tam);
int modificarTrabajo(eTrabajo listaTrabajo[], int tam, eServicio listaServicio[], int tamServicio);
int bajaTrabajo(eTrabajo listaTrabajo[], int tam);
void ordenarTrabajos(eTrabajo listaTrabajo[], int tam);
int listadoTrabajosYServicios(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio);
int listadoServicios(eServicio listaServicios[], int tam);


#endif /* ARRAYTRABAJOS_H_ */
