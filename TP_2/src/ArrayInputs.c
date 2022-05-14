/*
 * ArrayInputs.c
 *
 *  Created on: 11 may 2022
 *      Author: Familia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayInputs.h"

void rellenarInt(int* variable, char texto[])
{
	printf(texto);
	scanf("%d", variable);
	fflush(stdin);
}
void rellenarFloat(float* variable, char texto[])
{
	printf(texto);
	scanf("%f", variable);
	fflush(stdin);
}
void rellenarArrays(char arrayRecibido[], char textoMostrar[])
{
	printf(textoMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}

