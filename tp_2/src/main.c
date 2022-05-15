#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passenger.h"
#include "type.h"
#include "statusFlight.h"
#include "inform.h"

#include "extras.h"
#include "menu.h"

#define SIZE_PASSENGER 2000
#define SIZE_TYPE 3
#define SIZE_STATUSES 3

#define HARDCODESIZE 5


int main()
{
    Passenger passengers[SIZE_PASSENGER];
    Type types[SIZE_TYPE] = {{1000,"Economico"}, {1001,"Primera"}, {1002, "Diplomatico"}};
    StatusFlight statusesFlight[SIZE_STATUSES] = {{10000,"Activo"}, {10001,"Demorado"}, {10002, "Cancelado"}};

    char cont = 's';
    //int flag = 0;
    int nextIDPassenger = 1000;

    passenger_initializate(passengers, SIZE_PASSENGER);
    passenger_hardcode(passengers, HARDCODESIZE);
    nextIDPassenger += HARDCODESIZE;


    do{
        switch(menu_main())
        {
            case 1:
                if(passenger_add(nextIDPassenger,passengers, SIZE_PASSENGER, types, SIZE_TYPE, statusesFlight, SIZE_STATUSES)== 1)
                {
                	nextIDPassenger++;
                }
                //flag = 1;
                break;
            case 2:
                /*if(flag == 0)
                {
                    printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
                }
                else
                {*/
            		passenger_delete(passengers, SIZE_PASSENGER, types, SIZE_TYPE, statusesFlight, SIZE_STATUSES);
                //}
                break;
            case 3:
                /*if(flag == 0)
                {
                    printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
                }
                else
                {*/
                    passenger_modify(passengers, SIZE_PASSENGER, types, SIZE_TYPE, statusesFlight, SIZE_STATUSES);
                //}
                break;
            case 4:
                inform(passengers, SIZE_PASSENGER, types, SIZE_TYPE, statusesFlight, SIZE_STATUSES);
                break;
            case 5:
                if(confirm(5) == 1)
                {
                    cont = 'n';
                }
                break;
        }
    }while(cont == 's');

    return 0;
}
