/*
 * Controller.h
 *
 *  Created on: 30 jul. 2020
 *      Author: natyf
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayCartel);
int controller_sortLocalidad(LinkedList* pArrayListCartel);
int controller_ListCartel(LinkedList* pArrayListCartel);
int controller_modificarMedidas(LinkedList* pArrayListCartel);
int controller_saveAsText(char* path , LinkedList* pArrayListCartel);
void controller_imprimirCantCartelesMayorA100(LinkedList* pArrayListCartel);
void controller_imprimirCantCartelesOfrecidos(LinkedList* pArrayListCartel);
#endif /* CONTROLLER_H_ */
