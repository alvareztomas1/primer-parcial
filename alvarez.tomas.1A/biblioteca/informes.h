/** \brief Submenu con todas las opciones de informes
 *
 * \return opcion ingresada por el usuario
 *
 */
int subMenu();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Listado de el/los socios que realizo/realizaron mas solicitudes de prestamo
 *
 * \param soc estructura eSocio a recorrer
 * \param tamSoc tamaño de la estructura eSocio
 * \param pres estructura ePrestamo para recorrer y verificar los prestamos
 * \param tamPres tamaño de la estructura ePrestamo
 * \return void
 *
 */
void F_informarSocioMasSolicito (eSocio soc[], eLibros lib[], int tamLib, int tamSoc, ePrestamo pres[], int tamPres);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Lista los prestamos de todos los socios que realizaron al menos una solicitud a prestamo en una fecha determinada
 *
 * \param pres estructura ePrestamo
 * \param tamPres tamaño de la estructura ePrestamo
 * \param soc estructura eSocio a recorrer
 * \param tamSoc tamaño de la estructura eSocio
 * \param lib estructura eLibros que permite llamar a la funcion mostrarPrestamo
 * \param tamLib tamaño de la estructura eLibros
 * \return void
 *
 */
void H_informarPrestamoSocioConFechaDeterminada (ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Lista todos los libros solicitados a prestamo en una fecha determinada
 *
 * \param pres estructura ePrestamo a recorrer
 * \param tamPres tamaño de la estructura ePrestamo
 * \param soc estructura eSocio que me permite mostrar los prestamos
 * \param tamSoc tamaño de la estructura eSoocio
 * \param lib estructura eLibros a recorrer
 * \param tamLib tamaño de la estructura eLibros
 * \return void
 *
 */
void G_informarPrestamoLibrosConFechaDeterminada (ePrestamo pres[], int tamPres, eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Listado de todos los socios que solicitaron el prestamo de un libro determinado
 *
 * \param lib estructura eLibro que permite mostrar los libros
 * \param tamLib tamaño de la estructura eLibros
 * \param pres estructura ePrestamo a recorrer
 * \param tamPres tamaño de la estructura ePrestamo
 * \param soc estructura eSocio a recorrer
 * \param tamSoc tamaño de la estructura eSocio
 * \return void
 *
 */
void C_informarLibrosDeterminados (eLibros lib[],int tamLib,ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Listado de todos los libros que fueron solicitados a prestamo por un socio determinado
 *
 * \param lib estructura eLibros a recorrer
 * \param tamLib tamaño de la estructura eLibros
 * \param pres estructura ePrestamo a recorrer
 * \param tamPres tamaño de la estructura ePrestamo
 * \param soc estructura eSocio que permite encontrar al socio
 * \param tamSoc tamaño de la estructura eSocio
 * \return void
 *
 */
void D_informarSocioDeterminado (eLibros lib[],int tamLib, ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Listado de el/los libros menos solicitado/s en prestamo
 *
 * \param lib estructura eLibros a recorrer
 * \param tamLib tamaño de la estructura eLibros
 * \param pres estructura ePrestamo a recorrer
 * \param tamPres tamaño de la estructura ePrestamo
 * \return void
 *
 */
void E_informarLibroMenosPrestado (eLibros lib[],int tamLib, ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Listado de libros ordenados por titulo
 *
 * \param lib estructura eLibros a recorrer
 * \param tamLib tamaño de la estructura eLibros
 * \return void
 *
 */
void I_librosOrdenados (eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Listado de los socios ordenados por apellido
 *
 * \param soc estructura eSocio a recorrer
 * \param tamSoc tamaño de la estructura eSocio
 * \return void
 *
 */
void J_sociosOrdenados (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Informe del total general y promedio diario de las solicitudes a prestamo de los libros
 *
 * \param soc estructura eSocio para invocar a la funcion promedioDiario
 * \param tamSoc tamaño de la estructura eSocio
 * \param pres estructura ePrestamo para invocar a la funcion promedioDiario
 * \param tamPres tamaño de la estructura ePrestamo
 * \return void
 *
 */
void A_totalPromedio (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Informe de la cantidad de dias cuya solicitud de prestamo no no superan el promedio
 *
 * \param soc estructura eSocio para invocar a la funcion promedioDiario
 * \param tamSoc tamaño de la estructura eSocio
 * \param pres estructura ePrestamo para invocar a la funcion promedioDiario
 * \param tamPres tamaño de la estructura ePrestamo
 * \return void
 *
 */
void B_diasQueNoSuperanPromedio (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Cuenta la cantidad de prestamos y la cantidad de dias con prestamo
 *
 * \param soc estructura eSocio a recorrer
 * \param tamSoc tamaño de la estructura eSocio
 * \param pres estructura ePrestamo
 * \param tamPres tamaño de la estructura ePrestamo
 * \param contadorPrestamo cantidad de prestamos dados de alta
 * \param contadorDiario cantidad de dias con prestamos
 * \return void
 *
 */
void promedioDiario (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres, int *contadorPrestamo, int *contadorDiario);
