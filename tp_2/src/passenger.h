#include "type.h"
#include "statusFlight.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;


/** \brief Hardcodea los pasajeros
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param passengersToHardcode int La cantidad de pasajeros a harcodear
 * \return void
 *
 */
void passenger_hardcode(Passenger passengers[], int passengersToHardcode);

/** \brief Inicializa el array de pasajeros en 0 o vacio
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array
 * \return void
 *
 */
void passenger_initializate(Passenger passengers[], int lenPassengers);

/** \brief Busca lugar libre en el array de pasajeros para guardar nuevos datos
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int passenger_findFreeSpace(Passenger passengers[], int lenPassengers);

/** \brief Verifica la existencia de otro pasajero con el mismo ID
 *
 * \param id int El ID a buscar
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int passenger_findById(int id, Passenger passengers[], int lenPassengers);


/** \brief Da de alta un pasajero
 *
 * \param int id El id que se le asignara al pasajero
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array de pasajeros
 * \param types[] eType El array de tipos de moto
 * \param sizeTypes int El tamaño del array de tipos
 * \return int 1 si se pudo dar de alta, 0 si no se pudo
 *
 */
int passenger_add(int id, Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight);

/** \brief Da de baja un pasajero
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array de pasajeros
 * \param types[] eType El array de tipos de pasajeros
 * \param sizeTypes int El tamaño del array de tipos
 * \return void
 *
 */
void passenger_delete(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight);

/** \brief Modifica un pasajero
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array de pasajeros
 * \param types[] eType El array de tipos de pasajeros
 * \param sizeTypes int El tamaño del array de tipos
 * \return void
 *
 */

void passenger_modify(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight);

/** \brief Muestra las pasajeros cargados en una lista
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array de pasajeros
 * \param types[] eType El array de tipos de pasajeros
 * \param sizeTypes int El tamaño del array de tipos
 * \return void
 *
 */
void passenger_show(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight);

/** \brief Muestra solo un pasajero
 *
 * \param Passenger El pasajero a mostrar
 * \param types[] eType El array de tipos de pasajeros
 * \param sizeTypes int El tamaño del array de tipos
 * \return void
 *
 */
void passenger_showOne(Passenger, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight);

/** \brief Ordena las pasajeros
 *
 * \param passengers[] Passenger El array de pasajeros
 * \param lenPassengers int El tamaño del array de pasajeros
 * \param types[] eType El array de tipos de pasajeros
 * \param sizeTypes int El tamaño del array de tipos
 * \return void
 *
 */
void passenger_sort(Passenger passengers[], int lenPassengers, Type types[], int lenTypes);

/** \brief Carga la descripcion de los tipos de pasajeros
 *
 * \param description[] char Donde se cargara la informacion
 * \param id int El id de la estructura Type
 * \param types[] Type El array de tipos de pasajeros
 * \param lenTypes int El tamaño del array de tipos
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int passenger_loadTypeDescription(char description[], int id, Type types[], int lenTypes);

/** \brief Carga la descripcion de los estados de vuelo
 *
 * \param description[] char Donde se cargara la informacion
 * \param id int El id de la estructura Color
 * \param statusesFlight[] StatusFlight El array de estado de vuelo
 * \param lenStatusesFlight int El tamaño del array de estados de vuelo
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int passenger_loadStatusFlightDescription(char description[], int id, StatusFlight statusesFlight[], int lenStatusesFlight);

#endif /*PASSENGER_H_ */
