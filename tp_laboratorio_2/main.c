/******************************************************************************

    Datos:

    El sistema deberá tener el siguiente menú de opciones:
    1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
    de Id. El resto de los campos se le pedirá al usuario.
    2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
    o Salario o Sector
    3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
    4. INFORMAR:
        1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
        2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

    NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
    Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
    carga de algún empleado.
    Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
    facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
    detallan las funciones que esta biblioteca debe tener.

*******************************************************************************/

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

    eEmployee employee[TAM];

    resultadoInicializacion = initEmployees(employee, TAM);
    revisarResuladoInitEmployees(resultadoInicializacion);

    contadorId = 0;
    HardCodearArray(employee, 5);

    do
    {
        opcionIngresada = MostrarMenu(1, 5);

        switch(opcionIngresada)
        {
            case 1:
                contadorId++;
                contadorId = CargarEmpleado(employee, TAM, contadorId);
                break;
            case 2:
                ModificarUnEmpleado(employee, TAM);
                break;
            case 3:
                BajarEmpleado(employee, TAM);
                break;
            case 4:
                InformarListado(employee, TAM);
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
