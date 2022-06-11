#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int bandera = 0;
    int flagSave = 0;
    setbuf(stdout, NULL);


    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	printf("---------------------------------------------------\n"
    			"Menu:\n"
    			"---------------------------------------------------\n"
    			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero.\n"
				"4. Modificar datos de pasajero.\n"
				"5. Baja de pasajero.\n"
				"6. Listar pasajeros.\n"
				"7. Ordenar pasajeros.\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir.\n");
    	scanf("%d", &option);
    	fflush(stdin);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                bandera = 1;
                break;
            case 2:
            	controller_loadFromBinary("data.bin", listaPasajeros);
            	bandera = 1;
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	bandera = 1;
            	break;
            case 4:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");
            	}
            	else
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	break;
            case 5:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");

            	}
            	else
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	break;
            case 6:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");
            	}
            	else
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	break;
            case 7:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");
            	}
            	else
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	break;
            case 8:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");
            	}
            	else
            	{
            		controller_saveAsText("dataguardado.csv", listaPasajeros);
            		flagSave = 1;
            	}
            	break;
            case 9:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");
            	}
            	else
            	{
            		controller_saveAsBinary("data.bin", listaPasajeros);
            		flagSave = 1;
            	}
            	break;
            case 10:
            	printf("Muchas gracias, hasta luego.");
            	break;
            default:
            	printf("Error, Opcion Incorrecta");
        }
    }while(option != 10);
    return 0;
}

