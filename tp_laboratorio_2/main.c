#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "ArrayEmployees.h"

#define TAM 1000

int main()
{
    int opcionIngresada;
    int resultadoInicializacion;

    int contadorId;
    int bandera;

    eEmployee employee[TAM];

    resultadoInicializacion = initEmployees(employee, TAM);
    revisarResuladoInitEmployees(resultadoInicializacion);

    contadorId = 0;
    bandera = 0;
    //bandera = HardCodearArray(employee, 5);

    do
    {
        opcionIngresada = MostrarMenu(1, 5);

        switch(opcionIngresada)
        {
            case 1:
                contadorId++;
                contadorId = CargarEmpleado(employee, TAM, contadorId);
                bandera = 1;
                break;
            case 2:
                HacerLaLogicaDelCase2(employee, TAM, bandera);
                break;
            case 3:
                HacerLaLogicaDelCase3(employee, TAM, bandera);
                break;
            case 4:
                HacerLaLogicaDelCase4(employee, TAM, bandera);
                break;
            default:
                break;
        }
        system("pause");
        system("cls");
    }
    while(opcionIngresada != 5);

    return 0;
}
