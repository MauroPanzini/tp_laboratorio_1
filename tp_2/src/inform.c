#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passenger.h"
#include "type.h"
#include "statusFlight.h"
#include "inform.h"
#include "menu.h"
#include "extras.h"
#include "validations.h"

void inform(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    char cont = 's';

    system_clear("linux");
    printf("\n *** INFORMES ***************************************************************************");

     do{

        switch(menu_inform())
        {
            case 1:
            	passenger_show(passengers, lenPassengers, types, lenTypes, statusesFlight, lenStatusesFlight);
                break;
            case 2:
                //inform_passengersTotalAverage(passengers, lenPassengers, statusesFlight, lenStatusesFlight);
                break;
            case 3:
                inform_passengersFlycodeActive(passengers, lenPassengers, statusesFlight, lenStatusesFlight);
                break;
            case 4:
                cont = 'n';
                break;
        }

    }while(cont == 'y');
}

void inform_passengersFlycodeActive(Passenger passengers[], int lenPassengers, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    Passenger auxPassenger;

    for(int i=0; i<lenPassengers-1; i++)
    {
        for(int j=i+1; i<lenPassengers; i++)
        {
            if(strcmp(passengers[i].flycode, passengers[i + 1].flycode) > 0)
            {
					auxPassenger = passengers[i];
					passengers[i] = passengers[j];
					passengers[j] = auxPassenger;
            }
        }
    }
}

void inform_passengersTotalAverage(Passenger passengers[], int lenPassengers)
{
 //Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
	//for(int i=0; i<lenPassengers-1; i++)
	//{

	//}

}

