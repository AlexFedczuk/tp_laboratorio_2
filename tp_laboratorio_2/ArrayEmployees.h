typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

//Case 1
int initEmployees(eEmployee list[], int len);
void InicializarElementosArray(eEmployee lista[],int tam);
void revisarResuladoInitEmployees(int resultado);
//Case 2
int CargarEmpleado(eEmployee lista[], int tam, int contadorId);
int addEmployee(eEmployee list[], int len, int id, char name[], char lastName[], float salary, int sector);
int BuscarPrimerEspacioVacio(eEmployee lista[], int tam);
void revisarResuladoAddEmployee();
//Case 3
