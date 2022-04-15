/*
 ============================================================================
 Name        : TP_1.c
 Author      : Romero Melany Ingrid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#include "datos.h"

int main()
{
	setbuf(stdout, NULL);

	int opcionElegida;
	float kilometros=0;
	float precioLatam=0;
	float descuentoLatam=0;
	float aumentoLatam;
	float btcLatam;
	float unitarioLatam;
	float precioAerolineas=0;
	float descuentoAerolineas=0;
	float aumentoAerolineas;
	float btcAerolineas;
	float unitarioAerolineas;
	float diferencia;
	int flagUno=0;
	int flagDos=0;
	int flagTres=0;
	float precioLatamHard = 159339;
	float precioAerolineasHard = 162965;
	float kmHard = 7090;

	printf("------------------------------------\n");
	printf("¡¡Binvenido a la Agencia de Vuelos!!\n");
	printf("------------------------------------\n\n");
	do
	{
		printf("\n1- Ingresar Kilómetros: (km = %.2f). \n"
				"2- Ingresar Precio de Vuelos: (aerolineas = %.2f , latam = %.2f). \n"
				"3- Calcular todos los costos. \n"
				"4- Informar Resultados. \n"
				"5- Carga forzada de datos. \n"
				"6- Salir.", kilometros, precioAerolineas, precioLatam);

	 printf("\nIngrese la opcion deseada\n");
	 fflush(stdin);
	 scanf("%d", &opcionElegida);
	 switch(opcionElegida)
	 {
		 case 1:
			 printf("Ingrese los kilometrajes\n");
			 scanf("%f", &kilometros);

			 while(kilometros < 1)
			 {
				 printf("Error, ingrese un kilometraje valido\n");
				 fflush(stdin);
				 scanf("%f", &kilometros);

			 }
			 flagUno=1;
			 break;
		 case 2:
			 if(kilometros > 0)
			 {
				 printf("Ingresar precio de vuelo Aerolineas\n");
				 scanf("%f", &precioAerolineas);
				 while(precioAerolineas < 1)
				 {
					 printf("Error, ingrese un kilometraje valido\n");
					 fflush(stdin);
					 scanf("%f", &precioAerolineas);

				 }
				 printf("Ingresar precio de vuelo Latam\n");
				 scanf("%f", &precioLatam);
				 while(precioLatam < 1)
				 {
					 printf("Error, ingrese un kilometraje valido\n");
					 fflush(stdin);
					 scanf("%f", &precioLatam);
				 }
			 }
			 else
			 {
				 printf("Error, faltan ingresar datos(1)\n");
				 printf("Ingrese kilometrajes\n");
				 scanf("%f", &kilometros);
			 }
			 flagDos=1;
			 break;
		 case 3:
			 if(flagUno && flagDos)
			 {
				 printf("calcular todos los costos\n");
				 opcionTres(precioLatam, precioAerolineas, kilometros, &descuentoLatam, &aumentoLatam, &btcLatam, &unitarioLatam, &descuentoAerolineas, &aumentoAerolineas, &btcAerolineas, &unitarioAerolineas, &diferencia);
				 flagTres=1;
			 }
			 else
			 {
				 printf("Error, faltan ingresar datos(2,1)");
			 }
			 break;
		 case 4:
			 if(flagTres)
			 {
				 opcionCuatro(kilometros, precioAerolineas, descuentoAerolineas, aumentoAerolineas, btcAerolineas, unitarioAerolineas, precioLatam, descuentoLatam, aumentoLatam, btcLatam, unitarioLatam, diferencia);
			 }
			 else
			 {
				 printf("Error, faltan ingresar datos(3)");
			 }
			 break;
		 case 5:
			 opcionTres(precioLatamHard, precioAerolineasHard, kmHard, &descuentoLatam, &aumentoLatam, &btcLatam, &unitarioLatam, &descuentoAerolineas, &aumentoAerolineas, &btcAerolineas, &unitarioAerolineas, &diferencia);
			 opcionCuatro(kmHard, precioAerolineasHard, descuentoAerolineas, aumentoAerolineas, btcAerolineas, unitarioAerolineas, precioLatamHard, descuentoLatam, aumentoLatam, btcLatam, unitarioLatam, diferencia);
			 break;
		 case 6:
			 printf("Salir\n");
			 break;
		 default:
			 printf("Opcion Invalida");
	 }
	}
	while(opcionElegida !=6);

	printf("Muchas gracias por pasar por nuestra agencia de vuelos!!, vuelva pronto");

	return 0;
	}

