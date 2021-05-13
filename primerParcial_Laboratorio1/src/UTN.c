/*
 * UTN.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int numeroIngresado;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &numeroIngresado);
			if(numeroIngresado>=minimo && numeroIngresado<=maximo)
			{
				*pResultado=numeroIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFlotante(float* pResultadoFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float numeroIngresado;

	if(pResultadoFlotante!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &numeroIngresado);
			if(numeroIngresado>=minimo && numeroIngresado<=maximo)
			{
				*pResultadoFlotante=numeroIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getCaracter(char* pResultadoChar, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno=-1;
	char caracterIngresado;

	if(pResultadoChar!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%c", &caracterIngresado);
			if(caracterIngresado>=minimo && caracterIngresado<=maximo)
			{
				*pResultadoChar=caracterIngresado;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

	return retorno;
}

int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	char bufferString[64];
	int retorno=-1;

	do
	{
		printf("%s", mensaje);
	}while(reintentos>=0);

	return retorno;
}

int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}
