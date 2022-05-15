#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_


typedef struct
{
    int id;
    char description[20];
}StatusFlight;

#endif /* STATUSFLIGHT_H_ */


/** \brief Muestra los estados de vuelo cargados en una lista
 *
 * \param statusesFlight[] StatusFlight El array de estados de vuelos
 * \param lenStatusesFlight int El tamaño del array
 * \return void
 *
 */
void statusFlight_show(StatusFlight statusesFlight[], int lenStatusesFlight);

/** \brief Muestra un solo estado de vuelo
 *
 * \param statusFlight StatusFlight El estado de vuelo a mostrar
 * \return void
 *
 */
void statusFlight_showOne(StatusFlight statusFlight);

/** \brief Verifica la existencia de otro etsado de vuelo con el mismo ID
 *
 * \param id int El ID a buscar
 * \param statusesFlight[] StatusFlight El array de estados de vuelo
 * \param lenStatusesFlight int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int statusFlight_findOne(int id, StatusFlight statusesFlight[], int lenStatusesFlight);
