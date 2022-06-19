/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoDeVuelo[20];

}Passenger;

/**
 * @brief new abre la memoria dinamica y la cacia
 *
 * @pre
 * @post
 * @return nuevoPasajero
 */
Passenger* Passenger_new();
/**
 * @brief llena los datos del pasajero
 *
 * @pre
 * @post
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param tipoPasajeroStr
 * @param precioStr
 * @param flycodeStr
 * @param estadoDeVuelo
 * @return nuevoPasajero
 */
Passenger* Passenger_newParametros(char *idStr, char *nombreStr,char *apellidoStr, char *tipoPasajeroStr, char *precioStr,char *flycodeStr, char *estadoDeVuelo);
///**
// * @brief
// *
// * @pre
// * @post
// */
//void Passenger_delete();
/**
 * @brief setea id
 *
 * @pre
 * @post
 * @param this
 * @param id
 * @return
 */
int Passenger_setId(Passenger* this,int id);
/**
 * @brief guarda el id
 *
 * @pre
 * @post
 * @param this
 * @param id
 * @return retorno
 */
int Passenger_getId(Passenger* this,int* id);
/**
 * @brief setea el nombre
 *
 * @pre
 * @post
 * @param this
 * @param nombre
 * @return
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/**
 * @brief guarda el nombre
 *
 * @pre
 * @post
 * @param this
 * @param nombre
 * @return
 */
int Passenger_getNombre(Passenger* this,char* nombre);
/**
 * @brief setea el apellido
 *
 * @pre
 * @post
 * @param this
 * @param apellido
 * @return
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/**
 * @brief guarda el apellido
 *
 * @pre
 * @post
 * @param this
 * @param apellido
 * @return
 */
int Passenger_getApellido(Passenger* this,char* apellido);
/**
 * @brief setea el codigo de vuelo
 *
 * @pre
 * @post
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief guarda el codigo del vuelo
 *
 * @pre
 * @post
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief seta al tipo de pasajero
 *
 * @pre
 * @post
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/**
 * @brief guarda al tipo de pasajero
 *
 * @pre
 * @post
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
/**
 * @brief setea el precio
 *
 * @pre
 * @post
 * @param this
 * @param precio
 * @return
 */
int Passenger_setPrecio(Passenger* this,float precio);
/**
 * @brief guarda el precio
 *
 * @pre
 * @post
 * @param this
 * @param precio
 * @return
 */
int Passenger_getPrecio(Passenger* this,float* precio);
/**
 * @brief  guarda el estado del vuelo
 *
 * @pre
 * @post
 * @param this
 * @param estadoDeVuelo
 * @return
 */
int Passenger_getEstadoDeVuelo(Passenger *this, char *estadoDeVuelo);
/**
 * @brief setea el esta del vuelo
 *
 * @pre
 * @post
 * @param this
 * @param estadoDeVuelo
 * @return
 */
int Passenger_setEstadoDeVuelo(Passenger *this, char *estadoDeVuelo);
/**
 * @brief busca el id desocupado
 *
 * @pre
 * @post
 * @param pArrayListPassenger
 * @return
 */
int PassengerId(LinkedList *pArrayListPassenger);
/**
 * @brief busca el id
 *
 * @pre
 * @post
 * @param pArrayListPassenger
 * @param idABuscar
 */
void* PassengerBusqueda(LinkedList *pArrayListPassenger, int idABuscar);
/**
 * @brief muestra la lista
 *
 * @pre
 * @post
 * @param lecturaDeDato
 */
void PassengerLista(Passenger *lecturaDeDato);
int Passenger_compararNombre(void* nombreUno, void* nombreDos);

#endif /* PASSENGER_H_ */
