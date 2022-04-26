/*
 * miBiblioteca.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include <stdio.h>
#include <string.h>
#include "miBiblioteca.h"

void mostrarMenu(){
    printf("\nMenu pricipal\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. Salir\n\n");
}

int hardcodearEntidades(ePassenger* list, int len){
	int idAux[5] = {1,2,8,4,5};
	char nameAux[5][50] = {"Ana Sara","Fara Fareeha","Bastion Metzen","Brigitte Lindholm","Coto Argentino"};
	char lastNameAux[5][50] = {"Amari","Amari","Fortaleza","Reinhardt","YoTeConosco"};
	int priceAux[5] = {15000.234,20500.12,2225750.56,55400.78,42600.12};
	char flyCodeAux[5][50] = {"AR 1140","BR 3251","EU 1234","AR 1278","AR 4500"};
	int typePassengerAux[5] = {0,0,1,0,1};
	int statusFlightAux[5] = {1,1,1,1,0};
	int isEmptyAux[5] = {0,1,0,1,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].id = idAux[i];
	        strcpy(list[i].name, nameAux[i]);
	        strcpy(list[i].lastName, lastNameAux[i]);
	        list[i].price = priceAux[i];
	        strcpy(list[i].flyCode, flyCodeAux[i]);
	        list[i].typePassenger = typePassengerAux[i];
	        list[i].statusFlight = statusFlightAux[i];
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 5);

	return result;
}

int calcularIntMayor(int vec[], int len){
	int result;

	for(int i = 0; i < len; i++){
		if(i == 0){
			result = vec[i];
		}else if(result < vec[i]){
			result = vec[i];
		}
	}

	return result;
}

