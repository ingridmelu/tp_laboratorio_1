/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "ArrayInputs.h"
#include "calculo.h"
#define TAM 2000

int main(void)
{
	setbuf(stdout, NULL);
	int respuesta;
	int respuestaMenu;
	int buscarPosicion;
	int criterioDeOrden;
	int tipoDeBusqueda;
	float total;
	float promedio;
	int contadorMasPromedio;
	int validacionAdd;
	int validacionRemove;
	int validacionSort;
	int bandera = 0;

	int idAux=0;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	Passenger pasajeros[TAM];
	initPassengers(pasajeros, TAM);

	do
	{
		printf( "1- ALTAS: Ingresar pasajero. \n"
				"2- MODIFICAR: Modificar pasajero. \n"
				"3- BAJA: Eliminar pasajero. \n"
				"4- INFORMAR: Informar pasajeros. \n"
				"5- Ingreso forzado de pasajeros. \n"
				"6- Salir. \n"
				"Ingrese la opcion deseada.\n");
		scanf("%d", &respuesta);
		fflush(stdin);

		switch(respuesta)
		{
			case 1:

				idAux++;
				rellenarArrays(nameAux, "Ingresar el Nombre el pasajero\n");

				rellenarArrays(lastNameAux, "Ingresar el Apellido del pasajero\n");

				rellenarFloat(&priceAux, "Ingresar el precio del vuelo\n");

				rellenarArrays(flycodeAux, "Ingresar el codigo de vuelo\n");

				rellenarInt(&typePassengerAux, "Ingresar el tipo de pasajero\n");

				validacionAdd = addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				if(validacionAdd == -1)
				{
					printf("Error, vuelva a ingresar");
				}
				bandera = 1;
				break;
			case 2:
				if(bandera == 1)
				{
					rellenarInt(&idAux, "Ingresar ID del pasajero que desea modificar\n");

					buscarPosicion = findPassengerById(pasajeros, TAM, idAux);
					do
					{
						printf( "1- Modificar nombre. \n"
								"2- Modificar apellido. \n"
								"3- Modificar precio. \n"
								"4- Modificar codigo de vuelo. \n"
								"5- Modificar tipo de pasajero. \n"
								"6- Salir. \n"
								"Ingrese la opcion deseada.\n");
						scanf("%d", &respuestaMenu);
						fflush(stdin);

						switch(respuestaMenu)
						{
							case 1:
								rellenarArrays(pasajeros[buscarPosicion].name, "Ingrese el nombre");
								break;
							case 2:
								rellenarArrays(pasajeros[buscarPosicion].lastName, "Ingrese el apellido\n");
								break;
							case 3:
								rellenarFloat(&pasajeros[buscarPosicion].price, "Ingrese el precio del vuelo\n");
								break;
							case 4:
								rellenarArrays(pasajeros[buscarPosicion].flycode, "Ingresar el codigo del vuelo\n");
								break;
							case 5:
								rellenarInt(&pasajeros[buscarPosicion].typePassenger, "Ingrese el tipo de pasajero\n");
								break;
						}
					}while( respuestaMenu != 6);
				}

				break;
			case 3:
				if(bandera == 1)
				{
					rellenarInt(&idAux, "Ingresar ID del pasajero que desea eliminar \n");

					buscarPosicion = findPassengerById(pasajeros, TAM, idAux);
					pasajeros[buscarPosicion].isEmpty = -1;
					validacionRemove = removePassenger(pasajeros, TAM, buscarPosicion);
					if(validacionRemove == -1)
					{
						printf("Error, vuelva a ingresar");
					}
				}
				break;
			case 4:
				if(bandera == 1)
				{
					rellenarInt(&tipoDeBusqueda, "\n1-Ordenar por apellido y pasajero. \n2-Ordenar por codigo de vuelo.\n");
					rellenarInt(&criterioDeOrden, "\n1-Ordenar de manera ascendente. \n2-Ordenar de manera descendente.\n");
					total =  totalArrays(pasajeros, TAM);
					promedio = promedioArrays(pasajeros, TAM, total);
					contadorMasPromedio = contadorPromedioMayor(pasajeros, TAM, promedio);
					if(tipoDeBusqueda == 1)
					{
						validacionSort=sortPassengers(pasajeros, TAM, criterioDeOrden);
					}
					else
					{
						validacionSort=sortPassengersByCode(pasajeros, TAM, criterioDeOrden);
					}
					if(validacionSort == -1)
					{
						printf("Error, vuelva a ingresar");
					}

					printPassenger(pasajeros, TAM);
					printf("La suma de todos los precios da %f \n y el promedio es %f \n, %d pasajeros que superan ese promedio: \n", total, promedio, contadorMasPromedio);
				}
				break;
			case 5:
				idAux++;
				strcpy(nameAux, "Melany");
				strcpy(lastNameAux, "Romero");
				priceAux = TAM;
				typePassengerAux = 1;
				strcpy(flycodeAux, "JNI");
				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				idAux++;
				strcpy(nameAux, "Josias");
				strcpy(lastNameAux, "Rivola");
				priceAux = TAM;
				typePassengerAux = 1;
				strcpy(flycodeAux, "AEP");
				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				idAux++;
				strcpy(nameAux, "Marta");
				strcpy(lastNameAux, "Panelli");
				priceAux = TAM;
				typePassengerAux = 1;
				strcpy(flycodeAux, "EZE");
				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				idAux++;
				strcpy(nameAux, "Martin");
				strcpy(lastNameAux, "Telechea");
				priceAux = TAM;
				typePassengerAux = 1;
				strcpy(flycodeAux, "LPG");
				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				bandera = 1;
				break;
			case 6:
				printf("Muchas gracias, hasta luego");
				break;
			default:
				printf("Error, Opcion Incorrecta");
		}
	}while(respuesta != 6);
	return 0;
}
