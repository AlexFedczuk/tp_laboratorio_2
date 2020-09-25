typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

//Inicializacion
int initEmployees(eEmployee list[], int len);
void InicializarElementosArray(eEmployee lista[],int tam);
void revisarResuladoInitEmployees(int resultado);
void HardCodearArray(eEmployee lista[], int tam);

//Case 1
int CargarEmpleado(eEmployee lista[], int tam, int contadorId);
int addEmployee(eEmployee list[], int len, int id, char name[], char lastName[], float salary, int sector);
int BuscarPrimerEspacioVacio(eEmployee lista[], int tam);
void revisarResuladoAddEmployee();

//Case 2
void ModificarUnEmpleado(eEmployee lista[], int tam);
int findEmployeeById(eEmployee list[], int len,int id);
void RevisarResultadofindEmployeeById(int resultado);

//Case 3

//Case 4
