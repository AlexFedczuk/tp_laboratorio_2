/*
 * miBiblioteca.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "ArrayPassenger.h"
#define LEN 6 // El maximo es 2000, 2000 pasajeros!

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

/** \brief Esta funcion muestra el menu de opciones del menu principal..
*   \return void
*/
void mostrarMenu();
/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list Passenger* Pointer to array of passenger
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
int hardcodearEntidades(ePassenger* list, int len);

/** \brief Esta funcion devuelve el valor mayor de un vector de enteros.
*   \param int vec
*   \param int len
*   \return Devuelve el mayor valor del vector.
*/
int calcularIntMayor(int vec[], int len);

#endif /* MIBIBLIOTECA_H_ */
