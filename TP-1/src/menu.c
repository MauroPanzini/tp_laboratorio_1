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

// Pedimos los km //
/**
 * @brief pide al usuario ingresar los km por consola
 * @return retorna los km
 */
float pedirKm(){
	float km;
	printf("\nIngrese la cantidad de KM: ");
	scanf("\n%f", &km);
	return km;
}

// Pedimos el precio de Aeronlineas Argentinas //
/**
 * @brief pide al usuario ingresar el precio de Aerolineas Argentinas
 * @return retorna el precio
 */
float pedirPrecioAa(){
	float precioAa;
	printf("\nIngrese el precio del vuelo de Aalineas Argentinas: ");
	scanf("\n%f", &precioAa);

	return precioAa;
}
/**
 * @brief pide al usuario ingresar el precio de Latam
 * @return retorna el precio
 */
// Pedimos el precio de Latam //
float pedirPrecioLatam(){
	float precioLatam;
	printf("\nIngrese el precio del vuelo de Latam: ");
	scanf("\n%f", &precioLatam);

	return precioLatam;
}

// Calculamos el costo de AA y Latam, luego la diferencia de precio entre ambas //
/**
 * @brief calculas los costos de vuelo
 * @param precio le pasamos el precio de las aerolineas ingresado
 * @param km le pasamos los km ingresados
 * @param operacion le decimos qué operacion queremos hacer: 1)para debito 2) para credito 3)para btc 4)para el precio x km
 * @return retorna cada operacion que elijamos
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
 * @brief calcula la diferencia de precio entre una aerolínea y la otra
 * @param precioLatam le pasamos el precio de latam
 * @param precioAa le pasamos el precio de AA
 * @return retorna el valor obtenido
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

	printf("\nLatam:\n1)Precio con tarjeta de débito: $%f\n2)Precio con tarjeta de crédito: $%f\n3)Precio pagando con bitcoin: %f\n4)Precio unitario: $%f",debitoLatam, creditoLatam, btcLatam, precioXkmLatam);
	printf("\nAalíneas:\n1)Precio con tarjeta de débito: $%f \n2)Precio con tarjeta de crédito: $%f \n3)Precio pagando con bitcoin : %f \n4)Precio unitario: $%f", debitoAa, creditoAa, btcAa, precioXkmAa);
	printf("\nLa diferencia de precio es: %f ", difPrecio);
}