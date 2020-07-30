/*
 ============================================================================
 Name        : parcial2Labo-FernandezHerenda.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cartel.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);
	int opcion=0;

	LinkedList* listaCarteles = ll_newLinkedList();
	do
		{
			if(!utn_getNumero(&opcion,  "Ingrese la opcion a elegir:\n"
										"1. Leer el archivo con los datos de Servicio de Carteles y guardarlos en una lista.\n"
										"2. Ordenar lista generada, segun localidad de manera ascendente.\n"
										"3. Listar.\n"
										"4. Modificar medidas.\n"
										"5. guardar.\n"
										"6. Informes\n"
										"7. Salir", "La opcion ingresada es incorrecta\n", 1, 7, 2))
			switch(opcion)
			{
				case 1:
					controller_loadFromText("Datos_RSP_LABO1.csv",listaCarteles);
					break;
				case 2:
					controller_sortLocalidad(listaCarteles);
					break;
				case 3:
					controller_ListCartel(listaCarteles);
					break;
				case 4:
					controller_modificarMedidas(listaCarteles);
					break;
				case 5:
					controller_saveAsText("mapeado.csv" , listaCarteles);
					break;
				case 6:
					 controller_imprimirCantCartelesMayorA100(listaCarteles);
					 controller_imprimirCantCartelesOfrecidos(listaCarteles);
					break;
		}
		}while(opcion!=7);
		return 0;
}
