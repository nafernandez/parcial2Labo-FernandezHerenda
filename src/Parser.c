/*
 * Parser.c
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
#include <string.h>


int parser_cartelFromText(FILE *pFile, LinkedList *pArrayCartel)
{
	int ret = -1;
	char id[128];
	char tipo[128];
	char domicilio[128];
	char localidad[128];
	char estado[128];
	char medida[128];
	int i = 0;
	eCartel *pCartel;

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, tipo, domicilio,localidad,estado,medida);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, tipo, domicilio,localidad,estado,medida)==6)
			{
				pCartel = cartel_newParametros(id, tipo, domicilio,localidad,estado,medida);
				i++;
				if(pCartel!=NULL && i !=0)
				{
					ll_add(pArrayCartel, (eCartel*)pCartel);
					ret=0;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile)==0);
	return ret;
}

