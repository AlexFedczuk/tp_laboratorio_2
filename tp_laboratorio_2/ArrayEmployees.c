#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

//Case 1
int initEmployees(eEmployee list[], int len)
{
    int resultado;

    resultado = -1;

    if(list != 0 && len > 0)
    {
        InicializarElementosArray(list, len);
        resultado = 0;
    }

    return resultado;
}

void InicializarElementosArray(eEmployee lista[],int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        lista[i].id = 0;
        strcpy(lista[i].name, " ");
        strcpy(lista[i].lastName, " ");
        lista[i].salary = 0;
        lista[i].sector = 0;
        lista[i].isEmpty = 1;
    }
}

void revisarResuladoInitEmployees(int resultado)
{
    if(resultado == -1)
    {
        printf("\nHubo un error al inicializar el listado!\n");
        printf("Error! Invalid length or NULL pointer\n");
    }else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }
}

///*****************************************************************/
//Case 2
int CargarEmpleado(eEmployee lista[], int tam, int contadorId)
{
    int id;
    char nombre[25];
    char apellido[25];
    float salario;
    int sector;
    int  resultadoAddEmployee;
    char respuesta;

    int bandera;

    bandera = 0;

    do
    {
        if(bandera == 0)
        {
            id = contadorId;
        }else
        {
            id++;
        }

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(apellido);

        printf("Ingrese su salario: ");
        fflush(stdin);
        scanf("%f", &salario);

        printf("Ingrese su sector: ");
        fflush(stdin);
        scanf("%d", &sector);

        resultadoAddEmployee = addEmployee(lista, tam, id, nombre, apellido, salario, sector);
        revisarResuladoAddEmployee(resultadoAddEmployee);

        printf("Desea cargar otro empleado(s/n)?: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = tolower(respuesta);
        if(respuesta == 'n')
        {
            break;
        }

        bandera = 1;
    }
    while(respuesta != 'n');

    return id;
}

int addEmployee(eEmployee list[],
                int len,
                int id,
                char name[],
                char lastName[],
                float salary,
                int sector)
{
    int resultado;
    int espacioVacio;

    resultado = -1;

    espacioVacio = BuscarPrimerEspacioVacio(list, len);

    if(list != NULL && (len>0 && len<1001) && espacioVacio != -1)
    {
        list[espacioVacio].id = id;
        strcpy(list[espacioVacio].name, name);
        strcpy(list[espacioVacio].lastName, lastName);
        list[espacioVacio].salary = salary;
        list[espacioVacio].sector = sector;
        list[espacioVacio].isEmpty = 0;

        resultado=0;
    }

    return resultado;
}

int BuscarPrimerEspacioVacio(eEmployee lista[], int tam)
{
    int espacioVacio;

    int i;

    espacioVacio = -1;

    for(i = 0; i < tam; i ++)
    {
        if(lista[i].isEmpty == 1)
        {
            espacioVacio = i;
            break;
        }
    }

    return espacioVacio;
}

void revisarResuladoAddEmployee(int resultado)
{
    if(resultado == -1)
    {
        printf("\nHubo un error al realizar las ALTAS!\n");
        printf("Error! Invalid length or NULL pointer\n");
    }else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }
}

///*****************************************************************/
