/*
 * funcion.c
 *
 *  Created on: 10 abr 2022
 *      Author: Familia
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

#define BITCOIN 4606954.55

float descuentoDebito(float precio)
{
	return precio - (precio * 0.1);
}

float aumentoCredito(float importe)
{
	return importe + (importe * 0.25);
}

float divisionBitcoin(float precio)
{
	return precio / BITCOIN;
}

float precioPorKm(float precio, float kilometros)
{
	return precio / kilometros;
}
float diferenciaPrecio(float latam, float aerolineas)
{
	float diferencia;
	if(latam > aerolineas)
	{
		diferencia= latam - aerolineas;
	}
	else
	{
		if(aerolineas > latam)
		{
			diferencia = aerolineas - latam;
		}
	}
	return diferencia;
}

