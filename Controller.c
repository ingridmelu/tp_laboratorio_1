#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "imputs.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pArchivo;
	int validar = 0;

	pArchivo = fopen(path, "r");
	if (pArchivo == NULL)
	{
		return 0;
	}

	validar = parser_PassengerFromText(pArchivo, pArrayListPassenger);
	fclose(pArchivo);

	return validar;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pArchivo;
	int validar = 0;

	pArchivo = fopen(path, "rb");
	if (pArchivo == NULL)
	{
		printf("\nNo se puedo abrir el archivo.\n");
	}
	else
	{
		validar = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
	}
	fclose(pArchivo);

	return validar;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int idAux;
	char nombreAux[10];
	char apellidoAux[10];
	float precioAux;
	int tipoPasajero;
	char codigoVueloAux[10];
	char tipoPasajeroAux[10];
	char estadoDeVueloAux[20];
	int validacion;
	int retorno=0;
	char idCadena[10];
	char preciO[50];

	idAux = PassengerId(pArrayListPassenger);

	itoa(idAux, idCadena, 10);

    Passenger* nuevoPasajero;

    validacion = cadenaValidada(nombreAux, "Ingrese Nombre: \n");
    while (validacion == -1)
    {
        validacion = cadenaValidada(nombreAux, "Ingrese Nombre: \n");
	}

    validacion = cadenaValidada(apellidoAux,"Ingrese su Apellido: \n");
    while (validacion == -1)
	{
        validacion = cadenaValidada(apellidoAux,"Ingrese su Apellido: \n");
	}

    validacion = utn_getNumeroFlotante(&precioAux, "Ingrese el precio: \n","ERROR\n", 1,1000000000, 4);
    while (validacion == -1)
	{
        validacion = utn_getNumeroFlotante(&precioAux, "Ingrese el precio: \n","ERROR\n", 1,1000000000, 4);
	}

    validacion = utn_getNumEntero(&tipoPasajero, "Ingrese el tipo de pasajero: 1.Economica - 2.Ejecutiva - 3.Premium \n","ERROR\n", 1,3,4);
    while (validacion == -1)
	{
        validacion = utn_getNumEntero(&tipoPasajero, "Ingrese el tipo de pasajero: 1.Economica - 2.Ejecutiva - 3.Premium \n","ERROR\n", 1,3,4);
	}

	validacion = cadenaValidada(codigoVueloAux, "Ingrese el codigo de vuelo: \n");
	while (validacion == -1)
	{
		validacion = cadenaValidada(codigoVueloAux, "Ingrese el codigo de vuelo: \n");
	}

    switch(tipoPasajero)
	{
		case 1:
			strcpy(tipoPasajeroAux, "Economica");
			break;
		case 2:
			strcpy(tipoPasajeroAux, "Ejecutiva");
			break;
		case 3:
			strcpy(tipoPasajeroAux, "Premium");
			break;
	}

	itoa(precioAux, preciO, 10);

	nuevoPasajero = Passenger_newParametros(idCadena, nombreAux, apellidoAux,tipoPasajeroAux,preciO,codigoVueloAux, estadoDeVueloAux);

	if(nuevoPasajero != NULL)
	{
		printf("CARGADO CORRECTAMENTE.\n El ID que corresponde es %d \n,",nuevoPasajero->id);
		retorno = 1;
	    ll_add(pArrayListPassenger, nuevoPasajero);

	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int idABuscar;
	int opcionesMenu;
	int validar;
	int indx;
	char nombreAux[10];
	char apellidoAux[10];
	float precioAux;
	char codigoVueloAux[10];
	char estadoDeVueloAux[20];
	char preciO[50];
	int tipoPasajero;


	Passenger* pasajeroRetocado;

	utn_getNumEntero(&idABuscar, "Ingresar ID del pasajero que desea modificar: \n","¡¡¡¡ERROR!!!!" ,1, ll_len(pArrayListPassenger), 3);
	pasajeroRetocado = PassengerBusqueda(pArrayListPassenger, idABuscar);
	indx = ll_indexOf(pArrayListPassenger, pasajeroRetocado);
	pasajeroRetocado = ll_get(pArrayListPassenger, indx);

	do
	{
		printf("1-Ingrese su nombre: \n"
			   "2-Ingrese su apellido: \n"
			   "3-Ingrese el precio: \n"
			   "4-Ingrese el tipo de pasajero:  1.Economica - 2.Ejecutiva - 3.Premium\n"
			   "5-Ingrese el codigo de vuelo: \n"
			   "6-Ingrese el estado de vuelo: \n"
			   "7-Salir\n"
			   "Ingrese la opcion deseada:\n");
		scanf("%d", &opcionesMenu);
		fflush(stdin);

		switch(opcionesMenu)
		{
			case 1:
				validar = cadenaValidada(nombreAux, "Ingrese su Nombre: \n");

				while(validar == -1)
				{
					validar = cadenaValidada(nombreAux, "Ingrese su Nombre: \n");
				}
				 Passenger_setNombre(pasajeroRetocado, nombreAux);
				break;

			case 2:
				validar = cadenaValidada(apellidoAux,"Ingrese su Apellido: \n");

				while(validar == -1)
				{
					validar = cadenaValidada(apellidoAux,"Ingrese su Apellido: \n");
				}
				Passenger_setApellido(pasajeroRetocado, apellidoAux);
			break;

			case 3:
				validar = utn_getNumeroFlotante(&precioAux, "Ingrese el Precio: \n", "ERROR, ingrese el Precio: \n", 1,40, 4);

				while(validar == -1)
				{
					validar = utn_getNumeroFlotante(&precioAux, "Ingrese el Precio: \n", "ERROR, ingrese el Precio: \n", 1,40, 4);
				}

				Passenger_setPrecio(pasajeroRetocado, precioAux);

				itoa(precioAux, preciO, 10);
				break;

			case 4:
				validar = utn_getNumEntero(&tipoPasajero, "Ingrese el tipo de Pasajero: 1.Economica - 2.Ejecutiva - 3.Premium \n","ERROR\n", 1,4,4);

				while(validar == -1)
				{
					validar = utn_getNumEntero(&tipoPasajero, "Ingrese el tipo de Pasajero: 1.Economica - 2.Ejecutiva - 3.Premium \n","ERROR\n", 1,4,4);
				}
				Passenger_setTipoPasajero(pasajeroRetocado, tipoPasajero);
				break;
			case 5:
				validar = cadenaValidada(codigoVueloAux, "Ingrese el Codigo de vuelo: \n");

				while(validar == -1)
				{
					validar = cadenaValidada(codigoVueloAux, "Ingrese el Codigo de vuelo: \n");
				}
				Passenger_setCodigoVuelo(pasajeroRetocado, codigoVueloAux);
				break;
			case 6:
				validar = cadenaValidada(estadoDeVueloAux, "Ingrese el Estado de vuelo: \n");

				while(validar == -1)
				{
					validar = cadenaValidada(estadoDeVueloAux, "Ingrese el Estado de vuelo: \n");
				}
				Passenger_setEstadoDeVuelo(pasajeroRetocado, estadoDeVueloAux);
				break;
			case 7:
				printf("Salir \n");
				break;
			default:
				printf("Opcion invalida");
		}

	}while(opcionesMenu != 7);

    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{

		int idAEliminar;
		Passenger* pasajeroEliminado;
		int indx;
		int posicionAEliminar;

		utn_getNumEntero(&idAEliminar, "Ingrese la id que se va a elimnar: \n", "id no existente", 1, ll_len(pArrayListPassenger), 3);

		pasajeroEliminado = PassengerBusqueda(pArrayListPassenger, idAEliminar);
		indx = ll_indexOf(pArrayListPassenger, pasajeroEliminado);
		pasajeroEliminado = ll_get(pArrayListPassenger, indx);
		utn_getNumEntero(&posicionAEliminar, "Seguro que quiere eliminar este id? 1.si - 2.no \n", "1.si - 2.no \n", 1, 2, 3);
		printf("El pasajero se a eliminado\n");
		ll_remove(pArrayListPassenger, indx);
		return 1;

}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
		Node *posicionIndice = pArrayListPassenger->pFirstNode;
		Passenger *leer;

		printf("[ID:  ][ apellido - nombre: ][ precio:    ][ Tipo De Pasajero:  ][ Codigo De Vuelo: ]\n");
		for (; posicionIndice != NULL; posicionIndice = posicionIndice->pNextNode)
		{
			leer = posicionIndice->pElement;
			PassengerLista(leer);
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
		int retorno = 0;

		Node* primero = pArrayListPassenger->pFirstNode;
		Node* segundo;

		Passenger* primeraVerificacion;
		Passenger* segundaVerificacion;

		int indxOne;
		int indxTwo;

		for (primeraVerificacion = primero->pElement; primero != NULL; primero = primero->pNextNode)
		{

			primeraVerificacion = primero->pElement;
			if (primero->pNextNode != NULL)
			{
				segundo = primero->pNextNode;
				for (segundaVerificacion = segundo->pElement; segundo != NULL; segundo = segundo->pNextNode)
				{
					segundaVerificacion = segundo->pElement;
					if (primeraVerificacion->id > segundaVerificacion->id)
					{
						indxOne = ll_indexOf(pArrayListPassenger, primeraVerificacion);
						indxTwo = ll_indexOf(pArrayListPassenger, segundaVerificacion);
						ll_set(pArrayListPassenger, indxOne, segundaVerificacion);
						ll_set(pArrayListPassenger, indxTwo, primeraVerificacion);
						retorno = 1;
					}

				}
			}
		}
		return retorno;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pArchivo;

		int retorno = 1;
		pArchivo = fopen(path, "w");
		if (pArchivo == NULL)
		{
			retorno = 0;
		}

		int idAux;
		char nombre[50];
		char apellido[50];
		float precio;
		char flycode[8];
		char tipoPasajeroAux[15];
		int tipoPasajero;
		char statusFlight[15];

		Node *indice = pArrayListPassenger->pFirstNode;

		fprintf(pArchivo, "%s,%s,%s,%s,%s,%s,%s\n", "id", "name", "lastname", "price","flycode", "typePassenger", "statusFlight");

		for (; indice != NULL; indice = indice->pNextNode)
		{

			Passenger_getId(indice->pElement, &idAux);
			Passenger_getNombre(indice->pElement, nombre);
			Passenger_getApellido(indice->pElement, apellido);
			Passenger_getPrecio(indice->pElement, &precio);
			Passenger_getCodigoVuelo(indice->pElement, flycode);
			Passenger_getTipoPasajero(indice->pElement, &tipoPasajero);
			Passenger_getEstadoDeVuelo(indice->pElement, statusFlight);

			switch (tipoPasajero)
			{
			case 1:
				strcpy(tipoPasajeroAux, "economica");
				break;
			case 2:
				strcpy(tipoPasajeroAux, "ejecutiva");
				break;
			case 3:
				strcpy(tipoPasajeroAux, "premium");
				break;
			default:
				printf("Error, opcion no valida");
			}

			fprintf(pArchivo, "%d,%s,%s,%f,%s,%s,%s\n", idAux, nombre, apellido, precio,flycode, tipoPasajeroAux, statusFlight);

		}

		fclose(pArchivo);

		return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pArchivo;
	int retorno = 1;
	pArchivo = fopen(path, "wb");
	if (pArchivo == NULL)
	{
		retorno = 0;
	}

	Node *indice = pArrayListPassenger->pFirstNode;

	for (; indice != NULL; indice = indice->pNextNode)
	{
		fwrite(indice->pElement, sizeof(Passenger), 1, pArchivo);
	}
	fclose(pArchivo);

	return retorno;

}


