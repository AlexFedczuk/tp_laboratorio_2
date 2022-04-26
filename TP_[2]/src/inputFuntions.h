/*
 * funciones.h
 *
 *  Created on: Apr 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#include <stdbool.h>

#define BUFFER_SIZE 4096

#ifndef INPUT_FUNTIONS_H_
#define INPUT_FUNTIONS_H_

// Menues
/**
  @brief Esta funcion se encarga de validar que se ingreso un valor de tipo entero por consola.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Booleano.
*/
bool parseInt(char *string, int *integer);
/**
  @brief Esta funcion se encarga de validar que se ingreso un valor de tipo flotante por consola.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Booleano.
*/
bool parseFloat(char *string, float *nfloat);
/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo flotante.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Flotante.
*/
float pedirNumeroFlotante(char mensaje[]);
/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo entero.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Entero.
*/
int pedirNumeroEntero(char mensaje[]);
/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo entero NO negativo.
  @param ...
  @param ...
  @param ...
  @returns Deveuelve un valor de tipo Entero NO negativo.
*/
float pedirValorNoNegativo(char mensaje[]);

/** \brief Esta funcion pide por consola una cadena caracteres sin contenido NO alfabetico.
*   \param list Passenger*
*   \param length int
*   \return int*
*/
void pedirUnaCadenaAlpha(char cadena[], char mensaje[], int buffer);

/** \brief Esta funcion elimina los espacios blancos de la cadena ingresada.
*   \param char* cadena
*   \return int Return (-1) if Error [NULL pointer] - (0) if Ok
*/
int removerEspacios(char* cadena);

#endif /* INPUT_FUNTIONS_H_*/
