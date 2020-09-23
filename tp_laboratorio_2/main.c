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

void ModificarUnEmpleado(eEmployee lista[], int tam);
int findEmployeeById(eEmployee list[], int len,int id);
int PedirUnNumeroEntero(char mensaje[]);
float PedirUnNumeroFlotante(char mensaje[]);
void RevisarResultadofindEmployeeById(int resultado);

int main()
{
    int opcionIngresada;
    int resultadoInicializacion;

    int contadorId;

    eEmployee employee[TAM];

    resultadoInicializacion = initEmployees(employee, TAM);
    revisarResuladoInitEmployees(resultadoInicializacion);

    contadorId = 0;

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
                //printf("BAJA!");
                break;
            case 4:
                //printf("INFORMAR!");
                for(int i = 0; i < 1000; i++)
                {
                    printf("id: %d, name: %s, lastName: %s, salary: %.2f, sector: %d, isEmpty: %d\n",
                           employee[i].id,
                           employee[i].name,
                           employee[i].lastName,
                           employee[i].salary,
                           employee[i].sector,
                           employee[i].isEmpty);
                }
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

void ModificarUnEmpleado(eEmployee lista[], int tam)
{
    int idIngresado;
    int index;
    int opcion;

    idIngresado = PedirUnNumeroEntero("\nIngrese el ID del empleado que desea modificar: ");

    index = findEmployeeById(lista, tam, idIngresado);
    RevisarResultadofindEmployeeById(index);

    if(index != -1)
    {
        do
        {
            printf("\nQue desea modificar?\n");
            printf("1. NOMBRE\n");
            printf("2. APELLIDO \n");
            printf("3. SALARIO\n");
            printf("4. SECTOR\n");
            printf("5. CONTINUAR\n\n");
            printf("Ingrese una opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            if(opcion < 1 || opcion > 5)
            {
                printf("\nError! Opcion invalida!\n");
                printf("Ingresar una opcion del sub-menu: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }else
            {
                switch(opcion)
                {
                    case 1:
                        PedirUnaCadena(lista[index].name, 25, "\nIngrese el nuevo nombre: ");
                        break;
                    case 2:
                        PedirUnaCadena(lista[index].lastName, 25, "\nIngrese el nuevo apellido: ");
                        break;
                    case 3:
                        lista[index].salary = PedirUnNumeroFlotante("\nIngrese el nuevo sueldo: ");
                        break;
                    case 4:
                        lista[index].sector = PedirUnNumeroEntero("\nIngrese el numero del nuevo sector: ");
                        break;
                    default:
                        break;
                }
            }
        }
        while(opcion != 5);
    }
}

int findEmployeeById(eEmployee list[], int len,int id)
{
    int index;

    int i;

    index = -1;

    if(list != 0 && (len > 0 && len < 1001) && id > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
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

void RevisarResultadofindEmployeeById(int resultado)
{
    if(resultado == -1)
    {
        printf("\nHubo un error al buscar un ID!\n");
        printf("Error! Invalid length or NULL pointer received or employee not found\n");
    }else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }
}
