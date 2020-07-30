/*
 * Controller.c
 *
 *  Created on: 30 jul. 2020
 *      Author: natyf
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"
#include "Cartel.h"
#ifndef CONTROLLER_C_
#define CONTROLLER_C_

int controller_loadFromText(char* path , LinkedList* pArrayCartel)
{
	fflush(stdin);
	int retorno= 0;
	FILE* pFile=NULL;
	if(pArrayCartel!=NULL && path!=NULL)
	{
		pFile = fopen(path,"r");
		if(pFile !=NULL)
		{
			retorno= parser_cartelFromText(pFile,pArrayCartel);

			if(retorno==0)
			{
				printf("Se leyó\n");
			}else
			{
				printf("Error, no se llego a leer completo\n");
				fclose(pFile);
			}
		}else
		{
			printf("el archivo no pudo ser leido.\n");
		}

	}
    return retorno;
}
int controller_sortLocalidad(LinkedList* pArrayListCartel)
{
	int retorno=-1;
	if(pArrayListCartel!=NULL)
	{
		ll_sort(pArrayListCartel, cartel_OrdenamientoPorLocalidad, 1);
		retorno=0;
	}

	return retorno;
}
int controller_ListCartel(LinkedList* pArrayListCartel)
{
	int retorno = -1;
	if(pArrayListCartel!=NULL)
	{
		printf("ID-TIPO-DOMICILIO-LOCALIDAD-ESTADO-MEDIDA\n");
		retorno=ll_map( pArrayListCartel, cartel_imprimir);
	}

	return retorno;
}

int controller_modificarMedidas(LinkedList* pArrayListCartel)
{
	int retorno = -1;
	if(pArrayListCartel!=NULL)
	{
		retorno=ll_map( pArrayListCartel, cartel_modificacionMedidaPorEstadoId);
	}

	return retorno;

}
int controller_saveAsText(char* path , LinkedList* pArrayListCartel)
{
	int retorno=-1;
	FILE* nuevoArchivo;
	int i;
	eCartel* auxiliarCartel;
	int id;
	int tipo;
	char domicilio[128];
	char localidad[128];
	int estadoId;
	float medida;

	if(path!=NULL && pArrayListCartel!=NULL)
	{
		nuevoArchivo = fopen(path,"w+");
		for(i=0; i<ll_len(pArrayListCartel); i++)
		{
			auxiliarCartel=(eCartel*)ll_get(pArrayListCartel,i);
			cartel_getId(auxiliarCartel, &id);
			cartel_getTipo(auxiliarCartel, &tipo);
			cartel_getDomicilio(auxiliarCartel, domicilio);
			cartel_getLocalidad(auxiliarCartel, localidad);
			cartel_getEstadoId(auxiliarCartel, &estadoId);
			cartel_getMedida(auxiliarCartel, &medida);
			fprintf(nuevoArchivo,"%d %d %s %s %d %.2f\n",id, tipo, domicilio,localidad,estadoId,medida);
			retorno =0;
		}
		fclose(nuevoArchivo);
	}
    return retorno;
}

void controller_imprimirCantCartelesMayorA100(LinkedList* pArrayListCartel)
{
	int i=0;
	i=ll_count(pArrayListCartel, cartel_cantidadMayorA100);

	printf("La cantidad de carteles cuya medida es mayor a 100 son: %d\n", i);
}
void controller_imprimirCantCartelesOfrecidos(LinkedList* pArrayListCartel)
{
	int i=0;
	i=ll_count(pArrayListCartel, cartel_cantidadOfrecidos);

	printf("La cantidad de carteles ofrecidos son: %d\n", i);
}
#endif /* CONTROLLER_C_ */
