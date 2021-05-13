/*
 * utn.h
 *
 *  Created on: 23 abr. 2021
 *      Author: Lucas
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

float utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_H_ */
