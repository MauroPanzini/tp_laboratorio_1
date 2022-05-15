#ifndef TYPE_H_
#define TYPE_H_

typedef struct
{
    int id;
    char description[20];
}Type;

#endif // TYPE_H_


/** \brief Muestra los tipos cargados en una lista
 *
 * \param types[] Type El array de tipos
 * \param lenTypes int El tamaño del array
 * \return void
 *
 */
void type_show(Type types[], int lenTypes);

/** \brief Muestra un solo tipo
 *
 * \param type Type El tipo a mostrar
 * \return void
 *
 */
void type_showOne(Type type);

/** \brief Verifica la existencia de otro tipo con el mismo ID
 *
 * \param id int El ID a buscar
 * \param types[] Type El array de tipos
 * \param lenTypes int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int type_findOne(int id, Type types[], int lenTypes);
