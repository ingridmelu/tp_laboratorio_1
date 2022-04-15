/*
 * datos.c
 *
 *  Created on: 12 abr 2022
 *      Author: Familia
 */
#include "funcion.h"
#include <stdio.h>
void opcionTres(float precioLatam, float precioAerolineas, float kilometros, float* descuentoLatam, float* aumentoLatam,float* btcLatam, float* unitarioLatam,float* descuentoAerolineas, float* aumentoAerolineas,float* btcAerolineas,float* unitarioAerolineas, float* diferencia)
{
	*descuentoLatam = descuentoDebito(precioLatam);
	*aumentoLatam = aumentoCredito(precioLatam);
	*btcLatam = divisionBitcoin(precioLatam);
	*unitarioLatam = precioPorKm(precioLatam, kilometros);


	*descuentoAerolineas = descuentoDebito(precioAerolineas);
	*aumentoAerolineas = aumentoCredito(precioAerolineas);
	*btcAerolineas = divisionBitcoin(precioAerolineas);
	*unitarioAerolineas = precioPorKm(precioAerolineas, kilometros);

	*diferencia = diferenciaPrecio(precioAerolineas, precioLatam);
}
void opcionCuatro(float kilometros,float precioAerolineas,float descuentoAerolineas,float aumentoAerolineas,float btcAerolineas,float unitarioAerolineas,float precioLatam,float descuentoLatam,float aumentoLatam,float btcLatam,float unitarioLatam,float diferencia)
{
	 printf("KMs Ingresados: %.2f km\n\n"
			 "Precio Aerolineas: $%.2f\n"
			 "a) Precio con tarjeta de debito: $ %.2f \n"
			 "b) Precio con tarjeta de credito: $  %.2f \n"
			 "c) Precio pagando con bitcoin: %.7f BTC\n"
			 "d) Mostrar precio unitario:  $ %.2f \n\n"
			 "Precio Latam: $%.2f\n"
			 "a) Precio con tarjeta de debito: $ %.2f \n"
			 "b) Precio con tarjeta de credito: $ %.2f \n"
			 "c) Precio pagando con bitcoin: %.7f BTC\n"
			 "d) Mostrar precio unitario: $ %.2f \n\n"
			 "La diferencia de precio es de: $ %.2f \n", kilometros, precioAerolineas, descuentoAerolineas, aumentoAerolineas, btcAerolineas, unitarioAerolineas, precioLatam, descuentoLatam, aumentoLatam, btcLatam, unitarioLatam, diferencia);
}
