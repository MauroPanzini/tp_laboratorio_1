#include "passenger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extras.h"
#include "menu.h"
#include "validations.h"

#define TRUE 1
#define FALSE 0


void passenger_hardcode(Passenger passengers[], int passengersToHardcode)
{

    int ids[] = {1000,1001,1002,1003,1004};
    char names[][51] = {"Pepe", "Juan", "Maria", "Sofia", "Nicole"};
    char lastNames[][51] = {"Ramos", "Perez", "Fernandez", "Turner", "Smith"};
    float prices[] = {10000,10001,10002,10003,10004};
    char flycodes[][10] = {"abcdefg","aaabbbcc","acbacbacb","aabbccdd","abcdabcd"};
    int typesPassenger[] = {1000,1001,1002,1003,1004};
    int statusesFlight[] = {10000,10001,10002,10003,10004};

    for(int i=0; i<passengersToHardcode; i++)
    {
    	passengers[i].id = ids[i];
        strcpy(passengers[i].name, names[i]);
        strcpy(passengers[i].lastName, lastNames[i]);
        passengers[i].price = prices[i];
        strcpy(passengers[i].flycode, flycodes[i]);
        passengers[i].typePassenger =  typesPassenger[i];
        passengers[i].statusFlight =  statusesFlight[i];
        passengers[i].isEmpty = FALSE;
    }
}

void passenger_initializate(Passenger passengers[], int lenPassengers)
{
     for(int i=0; i<lenPassengers; i++)
     {
    	 passengers[i].isEmpty = TRUE;
     }
}

int passenger_findFreeSpace(Passenger passengers[], int lenPassengers)
{
    int ret = -1;

    for(int i=0; i<lenPassengers; i++)
    {
        if(passengers[i].isEmpty == TRUE)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int passenger_findById(int id, Passenger passengers[], int lenPassengers)
{
    int ret = -1;

    for(int i=0; i<lenPassengers; i++)
    {
        if(passengers[i].id == id && passengers[i].isEmpty == FALSE)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int passenger_add(int id, Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight)
{
	Passenger auxPassenger;
    int index = passenger_findFreeSpace(passengers, lenPassengers);
    int ok = 0;

    system_clear("linux");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system_pause("linux");
    }
    else
    {
        auxPassenger.id = id;

        validations_getText(auxPassenger.name,"\n\tIngrese el nombre del pasajero: ", "\n\t(!) Error. Caracteres invalidos o nombre muy corto.\n", 3, 51, 4);
        validations_getText(auxPassenger.lastName,"\n\tIngrese el apellido del pasajero: ", "\n\t(!) Error. Caracteres invalidos o apellido muy corto.\n", 3, 51, 4);
        validations_getFloat(&auxPassenger.price,"\n\tIngrese el precio del vuelo: ", "\n\t(!) Error. Ingrese un valor numerico flotante. Rango: 100-10000\n",1,1003,100,10000,4);
        validations_getText(auxPassenger.flycode,"\n\tIngrese el codigo de vuelo: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 10, 4);


        type_show(types, lenTypes);
        validations_getUnsignedInt(&auxPassenger.typePassenger,"\n\tIngrese la opcion del tipo de pasajero: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1000-1002\n",1,1002,1000,1002,4);

        statusFlight_show(statusesFlight, lenStatusesFlight);
        validations_getUnsignedInt(&auxPassenger.statusFlight,"\n\tIngrese la opcion del estado del vuelo: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 10000-10002\n",1,1003,10000,10002,4);


        auxPassenger.isEmpty = FALSE;

        passengers[index] = auxPassenger;

        printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
        system_pause("linux");
        ok = 1;
    }
    return ok;
}

void passenger_delete(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    int id;
    int index;

    system_clear("linux");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    passenger_show(passengers, lenPassengers, types, lenTypes, statusesFlight, lenStatusesFlight);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = passenger_findById(id, passengers, lenPassengers);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de un pasajero con el ID: %d <<<\n\n\n", id);
        system_pause("linux");
    }
    else
    {
        system_clear("linux");
        printf("\n\t\tEl pasajero que se dara de baja es:");
        printf("\n\t\t _________________________________________________________________________________________________________\n");
        printf("\n\t\t     ID              NOMBRE              APELLIDO       PRECIO        COD. VUELO        TIPO PASAJERO        ESTADO VUELO    ");
        printf("\n\t\t ________________________________________________________________________________________________________\n");
        passenger_showOne(passengers[index], types, lenTypes, statusesFlight, lenStatusesFlight);
        printf("\n\t\t ________________________________________________________________________________________________________\n\n");

        if(confirm(2))
        {
            passengers[index].isEmpty = TRUE;
        }
    }
}

void passenger_modify(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    int id;
    int index;

    int newType;

    system_clear("linux");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    passenger_show(passengers, lenPassengers, types, lenTypes, statusesFlight, lenStatusesFlight);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = passenger_findById(id, passengers, lenPassengers);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de un pasajero con el ID: %d <<<\n\n\n", id);
        system_pause("linux");
    }
    else
    {
        system_clear("linux");
        printf("\n\t\tEl pasajero que se modificara es:");
        printf("\n\t\t _________________________________________________________________________________________________________\n");
        printf("\n\t\t     ID              NOMBRE              APELLIDO       PRECIO        COD. VUELO        TIPO PASAJERO        ESTADO VUELO    ");
        printf("\n\t\t ________________________________________________________________________________________________________\n");
        passenger_showOne(passengers[index], types, lenTypes, statusesFlight, lenStatusesFlight );
        printf("\n\t\t ________________________________________________________________________________________________________\n\n");

        switch(menu_passengerModify())
        {
        case 1:
        	validations_getText(passengers[index].name,"\n\tIngrese el nombre del pasajero: ", "\n\t(!) Error. Caracteres invalidos o nombre muy corto.\n", 3, 51, 4);
            break;
        case 2:
      		validations_getText(passengers[index].lastName,"\n\tIngrese el apellido del pasajero: ", "\n\t(!) Error. Caracteres invalidos o apellido muy corto.\n", 3, 51, 4);
        	break;
        case 3:
        	validations_getFloat(&passengers[index].price,"\n\tIngrese el precio del vuelo: ", "\n\t(!) Error. Ingrese un valor numerico flotante. Rango: 100-10000\n",1,1003,100,10000,4);
        	break;
        case 4:
        	 type_show(types, lenTypes);
        	 validations_getUnsignedInt(passengers[index].typePassenger,"\n\tIngrese la opcion del tipo de pasajero: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1000-1002\n",1,1002,1000,1002,4);
        	 if(confirm(3))
        	 {
        		 passengers[index].typePassenger = newType;
        	 }
        	 break;
        case 5:
        	 validations_getText(passengers[index].flycode,"\n\tIngrese el codigo de vuelo: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 10, 4);
        	break;
        }

        printf("\n");
        printf("\n\t\t _________________________________________________________________________________________________________\n");
        printf("\n\t\t     ID              NOMBRE              APELLIDO       PRECIO        COD. VUELO        TIPO PASAJERO        ESTADO VUELO    ");
        printf("\n\t\t ________________________________________________________________________________________________________\n");
        passenger_showOne(passengers[index], types, lenTypes, statusesFlight, lenStatusesFlight);
        printf("\n\t\t ________________________________________________________________________________________________________\n\n");

        system_pause("linux");
    }
}

void passenger_show(Passenger passengers[], int lenPassengers, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    int flag = 0;

    printf("\n\t\t _________________________________________________________________________________________________________\n");
    printf("\n\t\t     ID              NOMBRE              APELLIDO       PRECIO        COD. VUELO        TIPO PASAJERO        ESTADO VUELO    ");
    printf("\n\t\t ________________________________________________________________________________________________________\n");

    passenger_sort(passengers, lenPassengers, types, lenTypes);

    for(int i=0; i<lenPassengers; i++)
    {
        if(passengers[i].isEmpty == FALSE)
        {
            passenger_showOne(passengers[i], types, lenTypes, statusesFlight, lenStatusesFlight);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

void passenger_showOne(Passenger passenger, Type types[], int lenTypes, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    char typeDescription[20];
    char statusFlightDescription[20];

    passenger_loadTypeDescription(typeDescription, passenger.typePassenger, types, lenTypes);
    passenger_loadStatusFlightDescription(statusFlightDescription, passenger.statusFlight, statusesFlight, lenStatusesFlight);


    printf("\n\t\t    %5d  %15s     %15s  %15f %15s %15s   %15s   \n", passenger.id, passenger.name, passenger.lastName, passenger.price, passenger.flycode, typeDescription, statusFlightDescription);
}


void passenger_sort(Passenger passengers[], int lenPassengers, Type types[], int lenTypes)
{
    Passenger auxPassenger;

    for(int i=0; i<lenPassengers-1; i++)
    {
        for(int j=i+1; i<lenPassengers; i++)
        {
            if(strcmp(passengers[i].lastName, passengers[i + 1].lastName) > 0)
            {
            	if(passengers[i].typePassenger > passengers[i + 1].typePassenger)
            	{
					auxPassenger = passengers[i];
					passengers[i] = passengers[j];
					passengers[j] = auxPassenger;
            	}
            }
        }
    }
}

int passenger_loadTypeDescription(char description[], int id, Type types[], int lenTypes)
{
    int ok = 0;

    for(int i=0; i<lenTypes; i++)
    {
        if(types[i].id == id)
        {
            strcpy(description, types[i].description);
            ok = 1;
        }
    }

    return ok;
}

int passenger_loadStatusFlightDescription(char description[], int id, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    int ok = 0;

    for(int i=0; i<lenStatusesFlight; i++)
    {
        if(statusesFlight[i].id == id)
        {
            strcpy(description, statusesFlight[i].description);
            ok = 1;
        }
    }

    return ok;
}
