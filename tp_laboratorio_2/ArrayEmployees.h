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
/** \brief To indicate that all position in the array are empty,
this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * \param list[] eEmployee Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[], int len);

/** \brief Inicializa todos los valores de cada posicion del Array
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return void
 *
 */
void InicializarElementosArray(eEmployee lista[],int tam);

/** \brief Revisa y avisa al usuario si hubo algun error
 *
 * \param resultado int Resultado de la funcion a revisar
 * \return void
 *
 */
void revisarResuladoInitEmployees(int resultado);

/** \brief Se encarga de HardCodear los valores del Array para testeo
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return void
 *
 */
void HardCodearArray(eEmployee lista[], int tam);

//Case 1
/** \brief Se encarga de hacer la logica, para realizar altas de empleados,
y devuelve el numero del ultimo id de un empleado
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \param contadorId int
 * \return int Devuelve el numero del ultimo id de un empleado
 *
 */
int CargarEmpleado(eEmployee lista[], int tam, int contadorId);

/** \brief add in a existing list of employees the values received as parameters
in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee list[], int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Se encarga de buscar y devolver el primer espacio vacio
que se encuentre
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return int El indice del espacio vacio encontrado
 *
 */
int BuscarPrimerEspacioVacio(eEmployee lista[], int tam);


/** \brief Se encarga de revisar y avisar si hubo un problema al
agregar un empleado al listado
 *
 * \param resultado int El resultado a revisar de la funcion addEmployee
 * \return void
 *
 */
void revisarResuladoAddEmployee(int resultado);

//Case 2

/** \brief Se encarga de hacer la logica para modificar un empleado
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return void
 *
 */
void ModificarUnEmpleado(eEmployee lista[], int tam);

/** \brief find an Employee by Id en returns the index position in array
 *
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]

 *
 */
int findEmployeeById(eEmployee list[], int len,int id);

/** \brief Se encarga de revisar el resultado y avisar a usuario
si hubo un error
 *
 * \param resultado int El resultado de la funcion a revisar findEmployeeById
 * \return void
 *
 */
void RevisarResultadofindEmployeeById(int resultado);

//Case 3

/** \brief Se encarga de hacer la logica para bajar un empleado
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return void
 *
 */
void BajarEmpleado(eEmployee lista[], int tam);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len, int id);

/** \brief Se encarga de revisar el resultado y avisar a
usuario si hubo un herror
 *
 * \param resultado int el resultado de la funcion a revisar removeEmployee
 * \return void
 *
 */
void RevisarResultadoRemoveEmployee(int resultado);

//Case 4
// Parte 1

/** \brief Se encarga de hacer la logica para informar la lista de empledos
y el resto de los datos necesarios
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return void
 *
 */
void InformarListado(eEmployee lista[], int tam);

/** \brief Mustra un pequenio menu pidiendole al usuario como quiere
ver el listado de empledos(alfabeticamente)
 *
 * \return int EL orden que eligio el usuario
 *
 */
int MostrarSubMenuCase4();

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order);

/** \brief Ordena el Array de empleados alfabeticamente de la A a la Z
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return int El resultado de la operacion
 *
 */
int OrdenarAlfabeticamenteDeLaAaZ(eEmployee lista[], int tam);

/** \brief Ordena el Array de empleados alfabeticamente de la Z a la A
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return int El resultado de la operacion
 *
 */
int OrdenarAlfabeticamenteDeLaZaA(eEmployee lista[], int tam);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee list[], int length);

//Parte 2
/** \brief Calcula el salario total de todos los empleados
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return float El  resultado de la opreacion calculada
 *
 */
float CalcularTotalDeSalarios(eEmployee lista[], int tam);

/** \brief Calcula cual es la cantidad total de empleados
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return float El  resultado de la opreacion calculada
 *
 */
int CalcularCantidadDeEmpleados(eEmployee lista[], int tam);

/** \brief Calcula el salario promedio entre todos los empleados
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return float El  resultado de la opreacion calculada
 *
 */
float CalcularPromedioDeSalarios(float totalSalarios, int cantidadEmpleados);

/** \brief Calcula cual es la cantidad de empleados que superan
el salario promedio
 *
 * \param lista[] eEmployee Puntero a la variedad de empleados
 * \param tam int Longitud de la matriz
 * \return float El  resultado de la opreacion calculada
 *
 */
int CalcularCantidadDeEmpleadosSalarioMayor(eEmployee lista[], int tam, float salarioPromedio);

