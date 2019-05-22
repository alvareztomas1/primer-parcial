#ifndef socios_H_INCLUDED
#define socios_H_INCLUDED
#include "socios.h"
#endif // socios_H_INCLUDED


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Inicializa el valor del campo itsEmpty en 1
 *
 * \param pres Array de estructura donde se inicializara el valor del campo
 * \param tamPres Tama�o de la estructura
 * \return Void
 *
 */

void inicializarPrestamo(ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recorre el array de estructura y busca que en alguno de los indices tengan un campo itsEmpty igual a 1
 *
 * \param  pres Array de estructuras a recorrer
 * \param tamPres tama�o de la estructura
 * \return  Indice donde encontro  el itsEmpty igual a 1. De no ser asi -2
 *
 */

int buscarPrestamoLibre (ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Pide los datos al usuario, verifica que esten bien, de ser asi da de alta el prestamo
 *
 * \param pres Array de Estructuras donde se guardan los datos del prestamo
 * \param tamPres Tama�o del array de estructura pres
 * \param soc Array de estructurtas que permite verificar que el legajo ingresado exista
 * \param tamSoc Tama�o del array de estructuras soc
 * \param lib Array de estructuras que me permite mostrar los libros disponibles
 * \param tamLib Tama�o del array de estructuras lib
 * \param contador Me permite volver autoincremental el campo idPrestamo
 * \return Void
 *
 */

void altaPrestamo (ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc, eLibros lib[], int tamLib, int contador);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recorre  los array de estructuras pres, soc y lib y en caso de que haya encontrado algun prestamo dado de alta lo muestra
 *
 * \param pres Array de estructura a recorrer
 * \param tamPres Tama�o de la estructura pres
 * \param  aut Array de estructura a recorrer
 * \param tamAut Tama�o de la estructura aut
 * \param lib Array de estructura a recorrer
 * \param tamLib Tama�o de la estructura lib
 * \return Void
 *
 */

void mostrarPrestamo (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres);


