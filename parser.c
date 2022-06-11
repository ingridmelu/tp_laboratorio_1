#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include <string.h>
#include "ctype.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pArchivo , LinkedList* pArrayListPassenger)
{
	Passenger *nuevo;

	char nombreAux[15];
	char apellidoAux[15];
	char precioAux[15];

	char flycodeAux[15];
	char tipoAux[15];

	char estado[15];

	char validacionApellido[15];

	int idAuxNumero;
	char idAux[10];

	int r;
	int flag = 0;

	if (pArchivo == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do
	{
		r = fscanf(pArchivo, "%[^,],%[^,],%[^, ^\n],%[^,],%[^,],%[^,],%[^\n]\n",idAux, nombreAux, apellidoAux, precioAux, flycodeAux, tipoAux,estado);

		if (r == 7)
		{
			if(flag != 0)
			{

				sscanf(apellidoAux, "%[a-zA-Z ]", validacionApellido);
				if (strcmp(apellidoAux, validacionApellido) == 0)
				{

					idAuxNumero = PassengerId(pArrayListPassenger);
					itoa(idAuxNumero, idAux, 10);

					nuevo = Passenger_newParametros(idAux, nombreAux, apellidoAux,tipoAux, precioAux, flycodeAux, estado);

					if (nuevo != NULL)
					{

						ll_add(pArrayListPassenger, nuevo);
					}
				}
			}
			flag = 1;
		}

	} while (!feof(pArchivo));

	fclose(pArchivo);
	return 1;

}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pArchivo , LinkedList* pArrayListPassenger)
{
	Passenger *nuevo;
	int cant;

	while (!feof(pArchivo))
	{
		nuevo = Passenger_new();

		cant = fread(nuevo, sizeof(Passenger), 1, pArchivo);
		if (cant != 1)
		{
			if (feof(pArchivo))
			{
				break;
			}
			else
			{
				printf("No se leyo");
				break;
			}
		}
		else
		{
			if (nuevo != NULL)
			{
				ll_add(pArrayListPassenger, nuevo);
			}

		}
	}

	return 1;
}
