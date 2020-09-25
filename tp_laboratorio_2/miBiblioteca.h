
/** \brief Esta funcion se encarga simplemente de solicitar al usuario
 una cadena de caracteres(Por ej: nombre, apellido, etc).
 *
 * \param cadena[] char. Este parametro sera el que se cargara con la
 cadena de caracteres que halla ingresado el usuario.
 * \param buffer int. La cantidad de caracteres que COMO MUCHO
 puede ocupar el string.
 * \param mensaje[] char. El mensaje que se le comunicara al usuario
 para instruirlo.
 * \return void
 *
 */
void PedirUnaCadena(char cadena[], int buffer, char mensaje[]);

/** \brief Esta funcion se ocupa de la primera parte de formalizar
un nombre y apellido, se ocupa de CONCATENAR 'apellido, nombre' y
pasar todo a minuscula.
 *
 * \param apellidoNombre[] char. El array donde se cargara el apellido
 y nombre concatenado.
 * \param apellido[] char. El apellido a procesar.
 * \param nombre[] char. El nombre a procesar.
 * \return void
 *
 */
void FormalizarApellidoNombreParte1(char apellidoNombre[], char apellido[], char nombre[]);

/** \brief Esta funcion se encarga de finalizar la formalizacion del
'apellido, nombre', dejando la primera letra del apellido/nombre con
mayuscula y el resto minuscula.
 *
 * \param buffer int. La cantidad de caracteres que puede ocupar
 COMO MUCHO el string
 * \param apellidoNombre[] char. El 'apellido, nombre' a terminar
de procesar
 * \return void
 *
 */
void FormalizarApellidoNombreParte2(int buffer, char apellidoNombre[]);

/** \brief Mostrar el menu del programa y devuelve la opcion
    elegida por el usuario
 *
 * \param opcionMenor int
 * \param opcionMayor int
 * \return La opcion elegida por el usuario.
 *
 */
int MostrarMenu(int opcionMenor, int opcionMayor);

/** \brief Pedirle un numero entero al usuario.
 *
 * \param mensaje[] char. El mensaje para instruir al usuario.
 * \return int. Devuelve el numero ingresado por el usuaario.
 *
 */
int PedirUnNumeroEntero(char mensaje[]);

/** \brief Pedirle un numero con coma al usuario.
 *
 * \param mensaje[] char. El mensaje para instruir al usuario.
 * \return float. Devuelve el numero ingresado por el usuaario.
 *
 */
float PedirUnNumeroFlotante(char mensaje[]);
