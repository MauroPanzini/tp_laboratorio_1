/*
 * menu.c
 *
 *  Created on: 6 abr. 2022
 *      Author: mauropanzini
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UN_BTC 4606954.55
/**
 * @brief	 		menu principal que toma la opcion elegida, y muestra el menu junto con los datos de las aerolineas
 * @param flagCase 	sirve para saber si ya se ingreso un dato a la opcion 2
 * @param aA 		le pasamos el precio de Aerolineas Argentinas para que lo muestre
 * @param latam 	le pasamos el precio de Latam para que lo muestre
 * @return 			retorna la opcione elegida
 */
int menuPrincipal(int flagCase, float aA, float latam){
	int opcion;
	if (flagCase == 1) {
		printf("\nBienvenido a GagonetaTravel, por favor elija una opcion:\n1)Ingresar Kilometros\n2)Ingresar precio de vuelos\n3)Calcular costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n");
		scanf("\n%d", &opcion);
	}
	else{
		printf("\nBienvenido a GagonetaTravel, por favor elija una opcion:\n1)Ingresar Kilometros\t\t\t\tEl precio de Aerolineas es: $%f\n2)Ingresar precio de vuelos\t\t\tEl precio de Latam es: $%f\n3)Calcular costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n", aA, latam);
		scanf("\n%d", &opcion);
	}

	return opcion;
}

// funcion para pedir datos numericos //

/**
 * @brief 			 nos toma por consola el dato numerico mayor a 0
 * @param mensaje	 le pedimos un mensaje para mostrar
 * @return 			 retorna el valor que ingresamos
 */
float pedirNumero(char* mensaje){
	float numero;
	printf("\n%s", mensaje);
	scanf("\n%f", &numero);
	while(numero<1){
		printf("\nError, ingrese un valor mayor a 0");
			scanf("\n%f", &numero);
	}
	return numero;
}

// Calculamos el costo de AA y Latam, luego la diferencia de precio entre ambas //
/**
 * @brief 				calcula los costos de vuelo
 * @param precio 		le pasamos el precio de las aerolineas ingresado
 * @param km 			le pasamos los km ingresados
 * @param operacion 	le decimos qué operacion queremos hacer: 1)para debito 2) para credito 3)para btc 4)para el precio x km
 * @return retorna 		cada operacion que elijamos
 */
float calcularCostos(float precio, float km, int operacion){

	float debito;
	float credito;
	float btc;
	float precioXkm;
	float retorno;

	switch(operacion){
	case 1:
		debito = precio - (precio*10/100);
		retorno = debito;
		break;
	case 2:
		credito = precio + (precio*25/100);
		retorno = credito;
		break;
	case 3:
		btc = precio/UN_BTC;
		retorno = btc;
		break;
	case 4:
		precioXkm = precio/km;
		retorno = precioXkm;
		break;
	default:
		retorno = 0;
		break;
	}
	return retorno;

}
/**
 * @brief 					calcula la diferencia de precio entre una aerolínea y la otra
 * @param precioLatam 		le pasamos el precio de latam
 * @param precioAa 			le pasamos el precio de AA
 * @return 					retorna el valor obtenido
 */
float diferenciaPrecio(float precioLatam, float precioAa){
	float difPrecio;
	difPrecio = (precioAa - precioLatam);
		if(difPrecio < 0){
			difPrecio = difPrecio * -1;
		}
	return difPrecio;
}

// Tomamos los datos anteriores y los mostramos por consola //
/**
 * @brief muestra por consola todos los datos
 * @param debitoLatam
 * @param creditoLatam
 * @param btcLatam
 * @param precioXkmLatam
 * @param debitoAa
 * @param creditoAa
 * @param btcAa
 * @param precioXkmAa
 * @param difPrecio
 */
void mostrarCostos(float debitoLatam, float creditoLatam, float btcLatam, float precioXkmLatam, float debitoAa, float creditoAa, float btcAa, float precioXkmAa, float difPrecio){

	printf("\nLatam:\n\n1)Precio con tarjeta de débito: $%f\n2)Precio con tarjeta de crédito: $%f\n3)Precio pagando con bitcoin: %f\n4)Precio unitario: $%f",debitoLatam, creditoLatam, btcLatam, precioXkmLatam);
	printf("\n\nAerolineas:\n\n1)Precio con tarjeta de débito: $%f \n2)Precio con tarjeta de crédito: $%f \n3)Precio pagando con bitcoin : %f \n4)Precio unitario: $%f", debitoAa, creditoAa, btcAa, precioXkmAa);
	printf("\n\nLa diferencia de precio es: $%f \n\n", difPrecio);
}
