#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passenger.h"
//#include "type.h"
//#include "informs.h"

#include "extras.h"
#include "menu.h"

#define SIZE_PASSENGER 10
#define SIZE_TYPE 5

#define HARDCODESIZE 5


int main()
{
    Passenger passengers[SIZE_PASSENGER];
    /*eType types[SIZE_TYPE] = {{1000,"Enduro"}, {1001,"Chopera"}, {1002, "Scooter"}, {1003, "Ciclomotor"}, {1004, "Cross"}};
    eColor colors[SIZE_COLOR] = {{10000,"Gris"}, {10001,"Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"}};
    eService services[SIZE_SERVICE] = {{20000, "Limpieza", 250}, {20001, "Ajuste", 300}, {20002, "Balanceo", 17}, {20003, "Cadena", 190}};
    eClient clients[SIZE_CLIENT] = {{0,"Mauro",'m'}, {1,"Nicole", 'f'}, {2, "Sofia", 'f'}, {3, "Jorge", 'm'}, {4, "Juan", 'm'}};
    eWork works[SIZE_WORK];
    eColor_MostChosen colors_mostChosen[SIZE_COLOR];
    ePatent patents[SIZE_PATENT] = {{10,"XVR452"},{11,"CAB140"},{12,"ACD150"},{13,"RHP123"}, {14,"LSP640"}};
    eClient_MasMotos client_MasMotos[SIZE_CLIENT];*/


    char cont = 's';
    int nextIDMoto = 1000;
    int nextIDWork = 0;
    //int flag = 0;


    moto_initializate(passengers, SIZE_PASSENGER);

    moto_hardcode(passengers, HARDCODESIZE);
    nextIDMoto += HARDCODESIZE;


    do{
        switch(menu_main())
        {
            case 1:
                if(passenger_add(nextIDMoto,passengers, SIZE_PASSENGER/*, types, SIZE_TYPE*/)== 1)
                {
                    nextIDMoto++;
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
            	passenger_delete(passengers, SIZE_PASSENGER/*, types, SIZE_TYPE*/);
                //}
                break;
            case 3:
                /*if(flag == 0)
                {
                    printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
                }
                else
                {*/
                    passenger_modify(passengers, SIZE_PASSENGER/*, types, SIZE_TYPE*/);
                //}
                break;
            case 4:
                //inform(motorcycles, SIZE_MOTO, types, SIZE_TYPE);
                break;
            case 5:
                if(confirm(12) == 1)
                {
                    cont = 'n';
                }
                break;
        }
    }while(cont == 's');

    return 0;
}
