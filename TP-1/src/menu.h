/*
 * menu.h
 *
 *  Created on: 6 abr. 2022
 *      Author: mauropanzini
 */

#ifndef MENU_H_
#define MENU_H_
float pedirNumero(char* mensaje);
float calcularCostos(float precio, float km, int operacion);
float diferenciaPrecio(float precioLatam, float precioAa);
void mostrarCostos(float debitoLatam, float creditoLatam, float btcLatam, float precioXkmLatam, float debitoAa, float creditoAa, float btcAa, float precioXkmAa, float difPrecio);



#endif /* MENU_H_ */
