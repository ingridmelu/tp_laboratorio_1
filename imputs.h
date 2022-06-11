/*
 * imputs.h
 *
 *  Created on: 23 may 2022
 *      Author: Familia
 */

#ifndef IMPUTS_H_
#define IMPUTS_H_

//void pedirEntero(int *variableRecibida, char textoAMostrar[]);
int utn_getNumEntero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int cadenaValidada(char arrayRecibido[], char textoAMostrar[]);
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


#endif /* INPUTH */
