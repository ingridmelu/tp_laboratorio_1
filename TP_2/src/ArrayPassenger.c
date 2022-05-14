/*
 * ArrayPassenger.c
 *
 *  Created on: 10 may 2022
 *      Author: Familia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len)
{
	for(int i = 0; i < len; i++)
	{
		list[i].isEmpty = -1;
	}
	return 0;
}
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	setbuf(stdout, NULL);

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == -1)
		{
			list[i].isEmpty = 0;

			list[i].id = id;

			list[i].price = price;

			list[i].typePassenger = typePassenger;
			strcpy(list[i].name, name);

			strcpy(list[i].lastName, lastName);

			strcpy(list[i].flycode, flycode);

			printf("El id del pasajero es: %d \n", list[i].id);
			i = len + 1;
		}
	}
	return 0;
}
int findPassengerById(Passenger* list, int len,int id)
{
	int posicionDevolver;
	if(list == NULL)
	{
		return -1;
	}
	for(int i = 0; i < len; i++)
	{
		if(list[i].id == id)
		{
			posicionDevolver = i;
		}
	}
	return posicionDevolver;
}
int removePassenger(Passenger* list, int len, int id)
{
	int eliminar = -1;
	int retorno =0;
	eliminar = findPassengerById(list, len, id);

	if(list == NULL)
	{
		return -1;
	}

	list[eliminar].isEmpty = -1;
	list[eliminar].id = -1;

	return retorno;
}
int sortPassengers(Passenger* list, int len, int order)
{
	int comparacion = 0;

	Passenger listA;
	if(list == NULL)
	{
		return -1;
	}
	for(int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{
				if (order == 1)
				{
					if(list[i].typePassenger > list[j].typePassenger)
					{
						comparacion = 1;
					}
					else
					{
						if(list[i].typePassenger == list[j].typePassenger)
						{
							comparacion = strcmp(list[i].lastName, list[j].lastName);
						}
					}
				}
				else
				{
					if(list[i].typePassenger < list[j].typePassenger)
					{
						comparacion = 1;
					}
					else
					{
						if(list[i].typePassenger == list[j].typePassenger)
						{
							comparacion = strcmp(list[j].lastName, list[i].lastName);
						}
					}
				}
				if (comparacion == 1)
				{
					comparacion = 0;

					listA.id = list[i].id;
					strcpy(listA.name, list[i].name);
					strcpy(listA.lastName, list[i].lastName);
					listA.price = list[i].price;
					strcpy(listA.flycode, list[i].flycode);
					listA.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listA.id;
					strcpy(list[j].name, listA.name);
					strcpy(list[j].lastName, listA.lastName);
					list[j].price = listA.price;
					strcpy(list[j].flycode, listA.flycode);
					list[j].typePassenger = listA.typePassenger;

					j = i+1;
				}
			}
		}
	}
	return 0;
}
int printPassenger(Passenger* list, int length)
{
	for(int i = 0; i < length; i++)
	{
		if(list[i].isEmpty != -1)
		{
			printf("%d | ", list[i].id);
			printf(list[i].lastName),
			printf(" | ");
			printf(list[i].name);
			printf(" | Precio: $%f | ", list[i].price);
			printf("Codigo de vuelo: %s | ", list[i].flycode);

			if(list[i].typePassenger == 1)
			{
				printf(" Mayor | ");
			}
			else
			{
				if(list[i].typePassenger == 2)
				{
					printf("Adolescente | ");
				}
				else
				{
					printf("Menor | ");
				}
			}
			if(list[i].statusFlight == 1)
			{
				printf(" Activo");
			}
			else
			{
				printf("Inactivo");
			}
			printf("\n");
		}
	}
	return 0;
}
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i;
	int j;
	int comparacion = 0;

	Passenger listA;
	if(list == NULL)
	{
		return -1;
	}
	for(i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{
				if (order == 1)
				{
					if(list[i].statusFlight > list[j].statusFlight)
					{
						comparacion = 1;
					}
					else
					{
						if(list[i].statusFlight == list[j].statusFlight)
						{
							comparacion = strcmp(list[i].flycode, list[j].flycode);
						}
					}
				}
				else
				{
					if(list[i].statusFlight < list[j].statusFlight)
					{
						comparacion = 1;
					}
					else
					{
						if(list[i].statusFlight == list[j].statusFlight)
						{
							comparacion = strcmp(list[j].flycode, list[i].flycode);
						}
					}
				}
				if (comparacion == 1)
				{
					comparacion = 0;

					listA.id = list[i].id;
					strcpy(listA.name, list[i].name);
					strcpy(listA.lastName, list[i].lastName);
					listA.price = list[i].price;
					strcpy(listA.flycode, list[i].flycode);
					listA.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listA.id;
					strcpy(list[j].name, listA.name);
					strcpy(list[j].lastName, listA.lastName);
					list[j].price = listA.price;
					strcpy(list[j].flycode, listA.flycode);
					list[j].typePassenger = listA.typePassenger;

					j = i+1;
				}
			}
		}
	}
	return 0;
}
