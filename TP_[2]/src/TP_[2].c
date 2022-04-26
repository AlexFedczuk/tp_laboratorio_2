/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main()
{
	setbuf(stdout, NULL);

    int opcionMenu;
    int opcionUnoCargada;
    int contadorId;

    ePassenger passengerList[LEN];

    opcionUnoCargada = 0;
    contadorId = 0;

    if(initPassengers(passengerList, LEN) == -1)
            printf("\nError! Invalid length or NULL pointer, al inicializar la lista de pasageros!\n");
    if(inicializarEntidades(passengerList, LEN) == -1)
            printf("\nError! Invalid length or NULL pointer, al inicializar la lista de pasageros!\n");

    contadorId = hardcodearEntidades(passengerList, LEN);
    if(contadorId == -1)
    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de pasageros!\n");

    do{
        mostrarMenu();
        opcionMenu = pedirNumeroEntero("Ingrese una opcion del menu principal: ");

        switch(opcionMenu)
        {
            case 1:
            	if(buscarEspacioVacio(passengerList, LEN) != -2){
            		contadorId++;
            		contadorId = cargarPasajero(passengerList, LEN, contadorId);// Falta pulir la carga de pasajeros, mirar el desarrollo de la funcion!
            		opcionUnoCargada = 1;
            	}else{
            		printf("\nERROR! Ya no quedan espacios en el programa para ingresar mas pasajeros!\n");
            	}

                break;
            case 2:
            	if(opcionUnoCargada == 1){
            		// ACA LA MODIFICACION
            	}else{
            	    printf("\nERROR! Se debe ingresar algun pasajero para realizar una modificacion!\n");
            	}
            	break;
            case 3:
                if(opcionUnoCargada == 1){
                	// ACA LA BAJA
                }else{
                	printf("\nERROR! Se debe ingresar algun pasajero para realizar una baja!\n");
                }
                break;
            case 4:
            	//printPassenger(passengerList, LEN);
            	if(opcionUnoCargada == 1){
            		printPassenger(passengerList, LEN);
            	}else{
            		printf("\nERROR! Se debe ingresar algun pasajero para realizar un informe!\n");
            	}
                break;
            default:
            	if(opcionMenu < 1 || opcionMenu > 5)
            	{
            		printf("\nERROR! Debe ingresar una opcion del menu principal!\n");
            	}
                system("pause");
                system("cls");// Por alguna razon, no la reconoce la funcion...
                break;
        }
    }while(opcionMenu != 5);

    return 0;
}
