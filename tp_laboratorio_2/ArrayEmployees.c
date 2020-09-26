#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "ArrayEmployees.h"

/***----------------------------------------Init -------*/
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

void HardCodearArray(eEmployee lista[], int tam)
{
    int id[5] = {1, 2, 3, 4, 5};
    char nombre[5][25] = {"Pepa", "Pepe", "Pepi", "Pepo", "Pepu"};
    char apellido[5][25] = {"Ram", "Rem", "Rim", "Rom", "Rum"};;
    float salario[5] = {25000.55 , 24500.50, 30000.35, 35000.25, 36250.45};
    int sector[5] = {1, 2, 3, 1, 4};
    //int isEmpty[5] = {1, 1, 1, 1, 1};
    int isEmpty[5] = {0, 1, 0, 0, 0};

    int i;

    for(i = 0; i < tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].name, nombre[i]);
        strcpy(lista[i].lastName, apellido[i]);
        lista[i].salary = salario[i];
        lista[i].sector = sector[i];
        lista[i].isEmpty = isEmpty[i];
    }
}

/***----------------------------------------Case 1 -------*/

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

/***----------------------------------------Case 2 -------*/

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

/***----------------------------------------Case 3 -------*/

void BajarEmpleado(eEmployee lista[], int tam)
{
    int idIngreado;
    int resultadoRemoveEmployee;

    idIngreado = PedirUnNumeroEntero("\nIngrese el ID del empleado que desea eliminar: ");

    resultadoRemoveEmployee = removeEmployee(lista, tam, idIngreado);
    RevisarResultadoRemoveEmployee(resultadoRemoveEmployee);
}

int removeEmployee(eEmployee list[], int len, int id)
{
    int i;
    int resultado;

    resultado = -1;

    if(list != 0 && (len > 0 && len < 1001) && id > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                list[i].isEmpty = 1;
                resultado = 0;
            }
        }
    }

    return resultado;
}

void RevisarResultadoRemoveEmployee(int resultado)
{
    if(resultado == -1)
    {
        printf("\nHubo un error al eliminar un empleado!\n");
        printf("Error! Invalid length or NULL pointer or can't find a employee\n");
    }else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }
}
