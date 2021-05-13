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

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam del array
 */
void inicializarTrabajo(eTrabajo listaTrabajo[], int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param
 */
void mostrarUnTrabajo(eTrabajo);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam tam del array
 * \return retorna estado
 */
int mostrarListadoTrabajos(eTrabajo listaTrabajo[], int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam del array
 * \param idTrabajo autoincremental
 * \return estado
 */
int altaTrabajo(eTrabajo listaTrabajo[], int tam, int *idTrabajo);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo disponibles
 * \param tam del array
 * \return estado
 */
int buscarTrabajoLibre(eTrabajo listaTrabajo[], int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam del array
 * \param listaServicio
 * \param tam del array servicio
 * \return
 */
int modificarTrabajo(eTrabajo listaTrabajo[], int tam, eServicio listaServicio[], int tamServicio);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam del array
 * \return estado
 */
int bajaTrabajo(eTrabajo listaTrabajo[], int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam del array
 */
void ordenarTrabajos(eTrabajo listaTrabajo[], int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tamTrabajo
 * \param listaServicios
 * \param tamServicio
 * \return estado
 */
int listadoTrabajosYServicios(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaServicios
 * \param tam
 * \return estado
 */
int listadoServicios(eServicio listaServicios[], int tam);


#endif /* ARRAYTRABAJOS_H_ */
