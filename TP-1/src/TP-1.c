/*
Trabajo práctico Nº1
Mauro Agustín Panzini
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


int main(void) {
	int opcion;
	int flagCase1 = 1; //Estas flagas son para saber si ya se cargaron datos o no
	int flagCase2 = 1; //En caso de haber cargado datos, la carga forzada no se puede utilizar
	int flagCase3 = 1;
	float km, precioAa, precioLatam, debitoAa, debitoLatam, creditoAa, creditoLatam, btcAa, btcLatam, precioXkmAa, precioXkmLatam, difPrecio;
		do{
			printf("\nBienvenido a GagonetaTravel, por favor elija una opcion:\n1)Ingresar Kilometros\n2)Ingresar precio de vuelos\n3)Calcular costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n");
			scanf("\n%d", &opcion);
			switch(opcion){					//Este switch es el principal que recorre el menu de opciones
			case 1:
				if (flagCase1 == 1) {		//Case 1 pedimos ingresar los km
					flagCase1 = 0;
					km = pedirKm();
				}
					break;
			case 2:							//Case 2 pedimos ingresar los precios de cada empresa
				if (flagCase2 == 1) {
					flagCase2 = 0;
					precioAa = pedirPrecio("Ingrese el precio de Aerolineas Argentinas: ");
					precioLatam = pedirPrecio("Ingrese el precio de Latam: ");
				}
				break;
			case 3:							//Case 3 hacemos las operaciones pertinentes en el orden que fueron dadas en la consigna
				if (flagCase3 == 1){
					flagCase3 = 0;
					debitoAa = calcularCostos(precioAa, km, 1);
					creditoAa = calcularCostos(precioAa, km, 2);
					btcAa = calcularCostos(precioAa, km, 3);
					precioXkmAa = calcularCostos(precioAa, km, 4);

					debitoLatam = calcularCostos(precioLatam, km, 1);
					creditoLatam = calcularCostos(precioLatam, km, 2);
					btcLatam = calcularCostos(precioLatam, km, 3);
					precioXkmLatam = calcularCostos(precioLatam, km, 4);

					difPrecio = diferenciaPrecio(precioLatam, precioAa);
				}
				break;
			case 4:																//Case 4 mostramos los resultados de las operaciones del Case 3
				if (flagCase1 == 0 && flagCase2 == 0 && flagCase3 == 0) {
					mostrarCostos(debitoLatam, creditoLatam, btcLatam, precioXkmLatam, debitoAa, creditoAa, btcAa, precioXkmAa, difPrecio);
					flagCase1 = 1;
					flagCase2 = 1;			//Reinicia las flags para poder volver a ingresar datos
					flagCase3 = 1;
				}
				else{															//En caso de que no se hayan ingresado datos, o no se haya operado con ellos
					printf("No hay informacion para mostrar");					// no nos mostrará nada
				}
				break;
			case 5:																//Case 5 carga forzadamente datos y opera automáticamente
				if (flagCase1 == 1 && flagCase2 == 1 && flagCase3 == 1) {
					precioAa = 162965;
					precioLatam = 159339;
					km = 7090;
					debitoAa = calcularCostos(precioAa, km, 1);
					creditoAa = calcularCostos(precioAa, km, 2);
					btcAa = calcularCostos(precioAa, km, 3);
					precioXkmAa = calcularCostos(precioAa, km, 4);

					debitoLatam = calcularCostos(precioLatam, km, 1);
					creditoLatam = calcularCostos(precioLatam, km, 2);
					btcLatam = calcularCostos(precioLatam, km, 3);
					precioXkmLatam = calcularCostos(precioLatam, km, 4);

					difPrecio = diferenciaPrecio(precioLatam, precioAa);
					mostrarCostos(debitoLatam, creditoLatam, btcLatam, precioXkmLatam, debitoAa, creditoAa, btcAa, precioXkmAa, difPrecio);

				}
				else{
					printf("Carga forzada no disponible, ya hay datos ingresados");	//Si hay datos ingresados, no se podrá hacer la carga
				}
				break;
			case 6:																//Case 6 finaliza el programa y nos muestra un mensjae
				printf("\n¡Hasta la proxima!");
				break;
			default:
				printf("\nError, ingrese un numero valido");
				break;
			}

		}while (opcion != 6);
		return 0;

	return EXIT_SUCCESS;
}
