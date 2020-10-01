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

    if(list != 0 && (len > 0 && len < 1001))
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
    }/*else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }*/
}

int HardCodearArray(eEmployee lista[], int tam)
{
    int id[5] = {1, 2, 3, 4, 5};
    char nombre[5][25] = {"pepa", "PePe", "PePI", "PepO", "PEPU"};
    char apellido[5][25] = {"pam", "ReM", "RiM", "ROm", "rum"};;
    float salario[5] = {25000.55 , 24500.50, 30000.35, 35000.25, 36250.45};
    int sector[5] = {1, 2, 3, 1, 4};
    //int isEmpty[5] = {1, 1, 1, 1, 1};
    int isEmpty[5] = {0, 1, 0, 0, 0};

    int bandera;
    int i;

    bandera = 1;

    for(i = 0; i < tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].name, nombre[i]);
        strcpy(lista[i].lastName, apellido[i]);
        lista[i].salary = salario[i];
        lista[i].sector = sector[i];
        lista[i].isEmpty = isEmpty[i];
    }

    return bandera;
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

    if(list != 0 && (len > 0 && len < 1001) && espacioVacio != -1)
    {
        list[espacioVacio].id = id;
        strcpy(list[espacioVacio].name, name);
        strcpy(list[espacioVacio].lastName, lastName);
        list[espacioVacio].salary = salary;
        list[espacioVacio].sector = sector;
        list[espacioVacio].isEmpty = 0;

        resultado = 0;
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
    }/*else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }*/
}

/***----------------------------------------Case 2 -------*/

void HacerLaLogicaDelCase2(eEmployee lista[], int tam, int bandera)
{
    if(bandera == 1)
    {
        ModificarUnEmpleado(lista, tam);
    }else
    {
        printf("\nError! Debe haber ingresado almenos un empleado para realizar esta operacion!\n\n");
    }
}

void ModificarUnEmpleado(eEmployee lista[], int tam)
{
    int idIngresado;
    int index;
    int opcion;

    int bandera;

    printEmployees(lista, tam);
    idIngresado = PedirUnNumeroEntero("\nIngrese el ID del empleado que desea modificar: ");

    index = findEmployeeById(lista, tam, idIngresado);
    RevisarResultadofindEmployeeById(index);

    bandera = 0;

    if(index != -1)
    {
        do
        {
            if(bandera == 0)
            {
                printf("\nQue desea modificar?\n");
            }else
            {
                printf("Desea modificar algo mas?\n");
            }
            printf("1. NOMBRE\n");
            printf("2. APELLIDO \n");
            printf("3. SALARIO\n");
            printf("4. SECTOR\n");
            printf("5. CONTINUAR\n\n");
            printf("Ingrese una opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            bandera = 1;

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
            system("pause");
            system("cls");
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
    }/*else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }*/
}

/***----------------------------------------Case 3 -------*/

void HacerLaLogicaDelCase3(eEmployee lista[], int tam, int bandera)
{
    if(bandera == 1)
    {
        BajarEmpleado(lista, tam);
    }else
    {
        printf("\nError! Debe haber ingresado almenos un empleado para realizar esta operacion!\n\n");
    }
}

void BajarEmpleado(eEmployee lista[], int tam)
{
    int idIngreado;
    int resultadoRemoveEmployee;

    printEmployees(lista, tam);
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
                break;
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
    }/*else
    {
        if(resultado == 0)
        {
            printf("\nOK\n");
        }
    }*/
}

/***----------------------------------------Case 4 -------*/

void HacerLaLogicaDelCase4(eEmployee lista[], int tam, int bandera)
{
    if(bandera == 1)
    {
        InformarListado(lista, tam);
    }else
    {
        printf("\nError! Debe haber ingresado almenos un empleado para realizar esta operacion!\n\n");
    }
}

void InformarListado(eEmployee lista[], int tam)
{
    int ordenDeMuestra;
    float totalSalarios;
    int cantidadDeEmpleados;
    float salarioPromedio;
    int cantidadEmpleadosSalarioMayor;

    ordenDeMuestra = MostrarSubMenuCase4();

    sortEmployees(lista, tam, ordenDeMuestra);

    totalSalarios = CalcularTotalDeSalarios(lista, tam);
    cantidadDeEmpleados = CalcularCantidadDeEmpleados(lista, tam);
    salarioPromedio = CalcularPromedioDeSalarios(totalSalarios, cantidadDeEmpleados);
    cantidadEmpleadosSalarioMayor = CalcularCantidadDeEmpleadosSalarioMayor(lista, tam, salarioPromedio);

    printEmployees(lista, tam);
    printf("\n   2.\n");
    printf("\n   Total de salarios: %.2f\n", totalSalarios);
    printf("   Salario promedio: %.2f\n", salarioPromedio);
    printf("   Cantidad de empleados que superan el salario promedio: %d\n\n", cantidadEmpleadosSalarioMayor);
}

void FormalizarNombresDeUnArray(eEmployee lista[], int tam, int buffer)
{
    int i;
    int j;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            for(j = 0; j < buffer; j++)
            {
                if(j == 0)
                {
                    lista[i].name[j] = toupper(lista[i].name[j]);
                }else
                {
                    if(lista[i].name[j] == ' ')
                    {
                        lista[i].name[j + 1] = toupper(lista[i].name[j + 1]);
                    }else
                    {
                        lista[i].name[j] = tolower(lista[i].name[j]);
                    }
                }
            }
        }
    }
}

void FormalizarApellidosDeUnArray(eEmployee lista[], int tam, int buffer)
{
    int i;
    int j;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            for(j = 0; j < buffer; j++)
            {
                if(j == 0)
                {
                    lista[i].lastName[j] = toupper(lista[i].lastName[j]);
                }else
                {
                    if(lista[i].lastName[j] == ' ')
                    {
                        lista[i].lastName[j + 1] = toupper(lista[i].lastName[j + 1]);
                    }else
                    {
                        lista[i].lastName[j] = tolower(lista[i].lastName[j]);
                    }
                }
            }
        }
    }
}

int MostrarSubMenuCase4()
{
    int opcion;

    printf("\nMostrar listado de empleados afabeticamente de A a Z(0) o Z a A(1)\n");

    do
    {
        printf("Ingrese aqui: ");
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

    FormalizarNombresDeUnArray(list, length, 25);
    FormalizarApellidosDeUnArray(list, length, 25);

    if(list != 0 && (length > 0 && length < 1001))
    {
        printf("\n   1.   ***** Listado de Empleados *****\n\n");
        printf("   ID      APELLIDO     NOMBRE     SALARIO        SECTOR");

        for(i = 0; i < length; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("\n   %04d    %s    %10s     %10.2f            %d\n", list[i].id,
                                                                             list[i].lastName,
                                                                             list[i].name,
                                                                             list[i].salary,
                                                                             list[i].sector);
            }
        }
    }

    return 0;
}

float CalcularTotalDeSalarios(eEmployee lista[], int tam)
{
    float acumulador;

    int i;

    acumulador = 0;

    if(lista != 0 && (tam > 0 && tam < 1001))
    {
        for(i = 0; i < tam; i ++)
        {
            if(lista[i].isEmpty == 0)
            {
                acumulador = acumulador + lista[i].salary;
            }
        }
    }

    return acumulador;
}

int CalcularCantidadDeEmpleados(eEmployee lista[], int tam)
{
    int contadorEmpleados;

    int i;

    contadorEmpleados = 0;

    if(lista != 0 && (tam > 0 && tam < 1001))
    {
        for(i = 0; i < tam; i ++)
        {
            if(lista[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
    }

    return contadorEmpleados;
}

float CalcularPromedioDeSalarios(float totalSalarios, int cantidadEmpleados)
{
    float promedioDeSalarios;

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
