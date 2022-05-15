#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "extras.h"
#include "validations.h"


int menu_main()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *                MENU                *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *    1.  ALTA DE PASAJEROS           *");
    printf("\n\t\t\t\t *    2.  BAJA DE PASAJEROS           *");
    printf("\n\t\t\t\t *    3.  MODIFICACION DE PASAJEROS   *");
    printf("\n\t\t\t\t *    4.  INFORMES                    *");
    printf("\n\t\t\t\t *    5.  SALIR                       *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *____________________________________*\n\n");
    option = getOption(5);

	return option;
}

int menu_passengerModify()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA MODIFICAR?         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. NOMBRE                          |");
    printf("\n\t\t\t\t |    2. APELLIDO                        |");
    printf("\n\t\t\t\t |    3. PRECIO                          |");
    printf("\n\t\t\t\t |    4. TIPO DE PASAJERO                |");
    printf("\n\t\t\t\t |    5. CODIGO DE VUELO                 |");
    printf("\n\t\t\t\t |    6. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(3);

    return option;
}

int menu_passengerSort()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |             ORDENAR POR               |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1.                                 |");
    printf("\n\t\t\t\t |    2.                                 |");
    printf("\n\t\t\t\t |    3.                                 |");
    printf("\n\t\t\t\t |    4.                                 |");
    printf("\n\t\t\t\t |    5.                                 |");
    printf("\n\t\t\t\t |    6.                                 |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(6);

    return option;
}

int menu_order()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |                ORDEN                  |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |           1. ASCENDENTE               |");
    printf("\n\t\t\t\t |          -1. DESCENDENTE              |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");
    validations_getSignedInt(&option, "\n\tIntroduzca una opcion: ", "\n\t(!) Error. Opcion inexistente\n", 1, sizeof(int),-1, 1,4);

    return option;
}

int menu_inform()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________________________");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |                       INFORMES                     |");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |   1.   INFORME PASAJEROS ORDENADOS                 |");
    printf("\n\t\t\t\t |   2.   INFORME TOTAL Y PROMEDIO                    |");
    printf("\n\t\t\t\t |   3.   INFORME CODIGO DE VUELOS                    |");
    printf("\n\t\t\t\t |   4.   VOLVER                                      |");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |____________________________________________________|\n\n");
    option = getOption(4);

    return option;
}

