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
float pedirKm(){
	float km;
	printf("\nIngrese la cantidad de KM: ");
	scanf("\n%f", &km);
	return km;
}

// Pedimos el precio de Aeronlineas Argentinas //
float pedirPrecioAa(){
	float precioAa;
	printf("\nIngrese el precio del vuelo de Aalineas Argentinas: ");
	scanf("\n%f", &precioAa);

	return precioAa;
}

// Pedimos el precio de Latam //
float pedirPrecioLatam(){
	float precioLatam;
	printf("\nIngrese el precio del vuelo de Latam: ");
	scanf("\n%f", &precioLatam);

	return precioLatam;
}

// Calculamos el costo de AA y Latam, luego la diferencia de precio entre ambas //
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

float diferenciaPrecio(float precioLatam, float precioAa){
	float difPrecio;
	difPrecio = (precioAa - precioLatam);
		if(difPrecio < 0){
			difPrecio = difPrecio * -1;
		}
	return difPrecio;
}

// Tomamos los datos anteriores y los mostramos por consola //
int mostrarCostos(float debitoLatam, float creditoLatam, float btcLatam, float precioXkmLatam, float debitoAa, float creditoAa, float btcAa, float precioXkmAa, float difPrecio){

	printf("\nLatam:\n1)Precio con tarjeta de débito: $%f\n2)Precio con tarjeta de crédito: $%f\n3)Precio pagando con bitcoin: %f\n4)Precio unitario: $%f",debitoLatam, creditoLatam, btcLatam, precioXkmLatam);
	printf("\nAalíneas:\n1)Precio con tarjeta de débito: $%f \n2)Precio con tarjeta de crédito: $%f \n3)Precio pagando con bitcoin : %f \n4)Precio unitario: $%f", debitoAa, creditoAa, btcAa, precioXkmAa);
	printf("\nLa diferencia de precio es: %f ", difPrecio);
return 0;
}
