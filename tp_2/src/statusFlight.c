#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "statusFlight.h"

void statusFlight_show(StatusFlight statusesFlight[], int lenStatusesFlight)
{
    printf("\n\t\t ******************* ESTADOS *******************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t        ID                    DESCRIPCION       \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<lenStatusesFlight; i++)
    {
    	statusFlight_showOne(statusesFlight[i]);
    }
}

void statusFlight_showOne(StatusFlight statusFlight)
{
    printf("\n\t\t       %d                  %10s\n", statusFlight.id, statusFlight.description);
}

int statusFlight_findOne(int id, StatusFlight statusesFlight[], int lenStatusesFlight)
{
    int ret = -1;

    for(int i=0; i<lenStatusesFlight; i++)
    {
        if(statusesFlight[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
