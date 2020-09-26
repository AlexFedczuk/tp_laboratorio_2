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

//Parte 1
void InformarListado(eEmployee lista[], int tam);
int MostrarSubMenuCase4();
int sortEmployees(eEmployee list[], int len, int order);
int OrdenarAlfabeticamenteDeLaAaZ(eEmployee lista[], int tam);
int OrdenarAlfabeticamenteDeLaZaA(eEmployee lista[], int tam);
int printEmployees(eEmployee list[], int length);

//Parte 2
float CalcularTotalDeSalarios(eEmployee lista[], int tam);
int CalcularCantidadDeEmpleados(eEmployee lista[], int tam);
float CalcularPromedioDeSalarios(float totalSalarios, int cantidadEmpleados);
int CalcularCantidadDeEmpleadosSalarioMayor(eEmployee lista[], int tam, float salarioPromedio);

int main()
{
    int opcionIngresada;
    int resultadoInicializacion;

    int contadorId;

    eEmployee employee[TAM];

    resultadoInicializacion = initEmployees(employee, TAM);
    revisarResuladoInitEmployees(resultadoInicializacion);

    contadorId = 0;
    //La funcion que se ocupa del testeo:
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
                /*for(int i = 0; i < 1000; i++)
                {
                    if(employee[i].isEmpty == 0)
                    {
                        printf("id: %d, name: %s, lastName: %s, salary: %.2f, sector: %d, isEmpty: %d\n",employee[i].id,
                                                                                                         employee[i].name,
                                                                                                         employee[i].lastName,
                                                                                                         employee[i].salary,
                                                                                                         employee[i].sector,
                                                                                                         employee[i].isEmpty);
                    }

                }*/
                /***AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAca te quedaste*/
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

void InformarListado(eEmployee lista[], int tam)
{
    int ordenDeMuestra;
    float totalSalarios;
    int cantidadDeEmpleados;
    float salarioPromedio;
    int cantidadEmpleadosSalarioMayor;

    printf("1. \n");
    ordenDeMuestra = MostrarSubMenuCase4();

    sortEmployees(lista, tam, ordenDeMuestra);

    printf("\n2. \n");
    totalSalarios = CalcularTotalDeSalarios(lista, tam);
    cantidadDeEmpleados = CalcularCantidadDeEmpleados(lista, tam);
    salarioPromedio = CalcularPromedioDeSalarios(totalSalarios, cantidadDeEmpleados);
    cantidadEmpleadosSalarioMayor = CalcularCantidadDeEmpleadosSalarioMayor(lista, tam, salarioPromedio);

    printEmployees(lista, tam);
    printf("\nTotal de salarios: %.2f\n", totalSalarios);
    printf("Salario promedio: %.2f\n", salarioPromedio);
    printf("Cantidad de empleados que superan el salario promedio: %d\n", cantidadEmpleadosSalarioMayor);
}

int MostrarSubMenuCase4()
{
    int opcion;

    printf("\nMostrar listado de empleados afabeticamente de A a Z(0) 0 Z a A(1)");

    do
    {
        printf("\nIngrese aqui: ");
        scanf("%d",&opcion);

        if(opcion < 0 || opcion > 1)
        {
            printf("\n   Error! Opcion invalida!");
        }
    }
    while(opcion < 0 || opcion > 1);

    return opcion;
}

int sortEmployees(eEmployee list[], int len, int order)
{
    int resultado;

    resultado = -1;

    if(list != 0 && (len > 0 && len < 1001) && (order > -1 && order < 2))
    {
        switch(order)
        {
            case 0:
                resultado = OrdenarAlfabeticamenteDeLaAaZ(list, len);
                break;

            case  1:
                resultado = OrdenarAlfabeticamenteDeLaZaA(list, len);
                break;

            default:
                break;
        }
    }


    return resultado;
}

int OrdenarAlfabeticamenteDeLaAaZ(eEmployee lista[], int tam)
{
    int resultado;
    int i;
    int j;

    eEmployee listaAux;

    resultado = -1;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(stricmp(lista[i].lastName, lista[j].lastName) == 1)
            {
                listaAux = lista[i];
                lista[i] = lista[j];
                lista[j] = listaAux;

                resultado = 0;
            }else
            {
                if(stricmp(lista[i].lastName, lista[j].lastName) == 0 &&
                   lista[i].sector > lista[j].sector)
                {
                    listaAux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = listaAux;

                    resultado = 0;
                }
            }
        }
    }

    return resultado;
}

int OrdenarAlfabeticamenteDeLaZaA(eEmployee lista[], int tam)
{
    int resultado;
    int i;
    int j;

    eEmployee listaAux;

    resultado = -1;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(stricmp(lista[i].lastName, lista[j].lastName) == -1)
            {
                listaAux = lista[i];
                lista[i] = lista[j];
                lista[j] = listaAux;

                resultado = 0;
            }else
            {
                if(stricmp(lista[i].lastName, lista[j].lastName) == 0 &&
                   lista[i].sector < lista[j].sector)
                {
                    listaAux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = listaAux;

                    resultado = 0;
                }
            }
        }
    }

    return resultado;
}

int printEmployees(eEmployee list[], int length)
{
    int i;

    printf("\n   1.   ***** Listado de Empleados *****\n\n");
    printf("ID      APELLIDO     NOMBRE     SALARIO        SECTOR");

    for(i = 0; i < length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("\n%04d    %s   %10s     %10.2f           %d\n", list[i].id,
                                                                    list[i].lastName,
                                                                    list[i].name,
                                                                    list[i].salary,
                                                                    list[i].sector);
        }
    }

    return 0;
}

float CalcularTotalDeSalarios(eEmployee lista[], int tam)
{
    float acumulador;

    int i;

    acumulador = 0;

    for(i = 0; i < tam; i ++)
    {
        if(lista[i].isEmpty == 0)
        {
            acumulador = acumulador + lista[i].salary;
        }
    }

    return acumulador;
}

int CalcularCantidadDeEmpleados(eEmployee lista[], int tam)
{
    int contadorEmpleados;

    int i;

    contadorEmpleados = 0;

    for(i = 0; i < tam; i ++)
    {
        if(lista[i].isEmpty == 0)
        {
            contadorEmpleados++;
        }
    }

    return contadorEmpleados;
}

float CalcularPromedioDeSalarios(float totalSalarios, int cantidadEmpleados)
{
    int promedioDeSalarios;

    if(cantidadEmpleados != 0)
    {
        promedioDeSalarios = totalSalarios / cantidadEmpleados;
    }

    return promedioDeSalarios;
}

int CalcularCantidadDeEmpleadosSalarioMayor(eEmployee lista[],
                                            int tam,
                                            float salarioPromedio)
{
    int cantidadEmpleados;

    int i;

    cantidadEmpleados = 0;

    for(i = 0; i < tam; i ++)
    {
        if(lista[i].salary > salarioPromedio && lista[i].isEmpty == 0)
        {
            cantidadEmpleados++;
        }
    }

    return cantidadEmpleados;
}
