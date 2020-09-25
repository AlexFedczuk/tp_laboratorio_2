#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"

void PedirUnaCadena(char cadena[], int buffer, char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);

    while(strlen(cadena) > buffer)
    {
        printf("\nError! No ingrese mas de %d caracteres!\n", buffer);
        printf(mensaje);
        fflush(stdin);
        gets(cadena);
    }
}

void FormalizarApellidoNombreParte1(char apellidoNombre[], char apellido[], char nombre[])
{
    strcpy(apellidoNombre, apellido);
    strcat(apellidoNombre, ", ");
    strcat(apellidoNombre, nombre);
    strlwr(apellidoNombre);
}

void FormalizarApellidoNombreParte2(int buffer, char apellidoNombre[])
{
    int i;

    for(i = 0; i < buffer; i++)
    {
        if(i == 0)
        {
            apellidoNombre[i] = toupper(apellidoNombre[i]);
        }else
        {
            if(apellidoNombre[i] == ' ')
            {
                apellidoNombre[i + 1] = toupper(apellidoNombre[i + 1]);
            }
        }
    }
}

int MostrarMenu(int opcionMenor, int opcionMayor)
{
    int opcionElegida;

    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n\n");
    printf("Ingresar opcion: ");
    fflush(stdin);
    scanf("%d", &opcionElegida);
    do
    {
        if(opcionElegida < opcionMenor || opcionElegida > opcionMayor)
        {
            printf("\nError! Opcion invalida!\n");
            printf("Ingresar una opcion del menu: ");
            fflush(stdin);
            scanf("%d", &opcionElegida);
        }
    }
    while(opcionElegida < opcionMenor || opcionElegida > opcionMayor);

    return opcionElegida;
}

int PedirUnNumeroEntero(char mensaje[])
{
    int numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

float PedirUnNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}
