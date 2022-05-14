/*
 * calculo.h
 *
 *  Created on: 13 may 2022
 *      Author: Familia
 */

#ifndef CALCULO_H_
#define CALCULO_H_
#include "ArrayPassenger.h"

float totalArrays(Passenger* valor, int longitud);
float promedioArrays(Passenger* valor, int longitud, float total);
int contadorPromedioMayor(Passenger* valor, int longitud, float total);
#endif /* CALCULO_H_ */
