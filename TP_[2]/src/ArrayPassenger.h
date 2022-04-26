/*
 * ArrayPassenger.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include <string.h>
#include <ctype.h>
#include "inputFuntions.h"

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}ePassenger;

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

/** \brief To indicate that all position in the array are empty,
*       this function put the flag (isEmpty) in TRUE in all
*       position of the array
*   \param list Passenger* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int len);

/** \brief Esta funcion inicializa los valores de todas las entidades, dentro de la lista ingresada.
*   \param list Passenger* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int inicializarEntidades(ePassenger* list, int len);

/** \brief Esta funcion se encarga de solicitar por la informacion necesaria para la carga de un pasajero.
* \param list passenger*
* \param len int
* \param contadorId int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int cargarPasajero(ePassenger list[], int len, int contadorId);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
   free space] - (0) if Ok
*/
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flyCode[]);

/** \brief Esta funcion busca en la lista ingresada, si hay espacio vacios, para ingresar un ingreso en el mismo, por ejemplo.
*   \param list Passenger* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer], (-2) si no hay espacios diponibles en la lista - (0) if Ok
*/
int buscarEspacioVacio(ePassenger* list, int len); // Listo.

/** \brief print the content of passengers array
*
*   \param list Passenger*
*   \param length int
*   \return int*
*/
int printPassenger(ePassenger* list, int length);

#endif /* ARRAYPASSENGER_H_ */
