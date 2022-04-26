/*
 * ArrayPassenger.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 *
 *      FALTA, MIRAR BIEN LA HOJA
 */
#include <stdio.h>
#include "ArrayPassenger.h"

int initPassengers(ePassenger* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].isEmpty = 1;
        }
        result = 0;
    }

    return result;
}

int inicializarEntidades(ePassenger* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].id = 0;
            strcpy(list[i].name, " ");
            strcpy(list[i].lastName, " ");
            list[i].price = -1;
            strcpy(list[i].flyCode, " ");
            list[i].typePassenger = -1;
            list[i].statusFlight = -1;
        }
        result = 0;
    }

    return result;
}

int cargarPasajero(ePassenger list[], int len, int contadorId)
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    char respuesta;
    int bandera = 0;

    do{
        if(bandera == 0){
            id = contadorId;
        }
        else{
            id++;
        }

        pedirUnaCadenaAlpha(name, "\nIngrese el nombre del pasajero: ", 51); // Luego cambiar el '51' por BUFFE una CONSTANTER, validar el LEN, sino no entra
        pedirUnaCadenaAlpha(lastName, "\nIngrese el apellido del pasajero: ", 51);// Luego cambiar el '51' por BUFFE una CONSTANTER, validar el LEN, sino no entra
        price = pedirNumeroFlotante("\nIngrese el precio: ");
        printf("\nIngrese el codigo de vuelo: "); // validar el LEN, sino no entra
        fflush(stdin);
        gets(flyCode);
        typePassenger = pedirNumeroEntero("\nIngrese tipo de pasajero (0) o (1): "); //Esto habria que validarlo...
        statusFlight = pedirNumeroEntero("\nIngrese el estado del vuelo (0) o (1): "); //Esto habria que validarlo...

        if(addPassenger(list, len, id, name, lastName, price, typePassenger, statusFlight, flyCode) == -1) // LE FALTA TERMINAR
        	printf("\nError! Invalid length or NULL pointer, al agregar el pasajero a la lista!\n");

        printf("\nDesea cargar otro pasajero(s/n)?: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = tolower(respuesta);
        if(respuesta == 'n')
            break;

        bandera = 1;
    }
    while(respuesta != 'n');
    fflush(stdin);

    return id;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flyCode[]){
	int espacioVacio;
	int resultado = -1;

	espacioVacio = buscarEspacioVacio(list, len);

	if(list != 0 && len > 0 && espacioVacio != -1)
	{
		list[espacioVacio].id = id;
	    strcpy(list[espacioVacio].name, name);
	    strcpy(list[espacioVacio].lastName, lastName);
	    list[espacioVacio].price = price;
	    strcpy(list[espacioVacio].flyCode, flyCode);
	    list[espacioVacio].typePassenger = typePassenger;
	    list[espacioVacio].statusFlight = statusFlight; // Parece que se olvido de este parametro?
	    list[espacioVacio].isEmpty = 0;
	    resultado = 0;
	}

	return resultado;
}

int buscarEspacioVacio(ePassenger* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 1)
            {
                result = i;
                break;
            }else{
                result = -2;
            }
        }
    }

    return result; // -1 si el puntero es NULL o LEN invalido, -2 si no hay espacios vacios. Si hay espacio, devuelvo el indice [i] de esa ubicacion.
}

int printPassenger(ePassenger* list, int length)
{
    int result = -1;

    if(list != NULL && length > 0){
        printf("\n");
        for(int i = 0; i < length; i++){
        	if(list[i].isEmpty == 0){
        		printf("ID: %04d, Name: %20s, Last Name: %20s, Price: %11.2f, Fly Code: %10s, Type Passenger: %2d, Status Flight: %2d\n",
                                                                                                                                    list[i].id,
                                                                                                                                    list[i].name,
                                                                                                                                    list[i].lastName,
                                                                                                                                    list[i].price,
                                                                                                                                    list[i].flyCode,
                                                                                                                                    list[i].typePassenger,
                                                                                                                                    list[i].statusFlight);
        	}
        }
        result = 0;
    }

    return result;
}


