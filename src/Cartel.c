/*
 * Cartel.c
 *
 *  Created on: 30 jul. 2020
 *      Author: natyf
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cartel.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

static int isValidString(char* cadena,int longitud);

static int isValidString(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
eCartel* cartel_new(void)
{
	eCartel* auxiliarPuntero = NULL;
	auxiliarPuntero = (eCartel*) malloc(sizeof(eCartel));
	return auxiliarPuntero;
}

eCartel* cartel_newParametros(char* id, char* tipo,char* domicilio,char* localidad, char* estadoId, char* medida)
{
	eCartel* this = NULL;
	this = cartel_new();
	if(this!=NULL)
	{
		this->id=atoi(id);
		this->tipo=atoi(tipo);
		strncpy(this->domicilio,domicilio,128);
		strncpy(this->localidad,localidad,128);
		this->estadoId=atoi(estadoId);
		this->medida=atof(medida);
	}else
	{
		cartel_delete(this);
		this=NULL;
	}
	return this;
}

void cartel_delete(eCartel* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int cartel_setId(eCartel* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int cartel_getId(eCartel* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}
int cartel_setTipo(eCartel* this,int tipo)
{
	int retorno = -1;
	if(this != NULL && tipo > 0)
	{
		retorno = 0;
		this->tipo = tipo;
	}
	return retorno;
}

int cartel_getTipo(eCartel* this,int* tipo)
{
	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		*tipo = this->tipo;
	}
	return retorno;
}
int cartel_setDomicilio(eCartel* this,char* domicilio)
{
	int retorno = -1;
	if(this != NULL && domicilio != NULL)
	{
		if(isValidString(domicilio,128))
		{
			retorno = 0;
			strncpy(this->domicilio,domicilio,128);
		}
	}
	return retorno;
}

int cartel_getDomicilio(eCartel* this,char* domicilio)
{
	int retorno = -1;
	if(this != NULL && domicilio != NULL)
	{
		retorno = 0;
		strncpy(domicilio,this->domicilio,128);
	}
	return retorno;
}

int cartel_setLocalidad(eCartel* this,char* localidad)
{
	int retorno = -1;
	if(this != NULL && localidad != NULL)
	{
		if(isValidString(localidad,50))
		{
			retorno = 0;
			strncpy(this->localidad,localidad,50);
		}
	}
	return retorno;
}

int cartel_getLocalidad(eCartel* this,char* localidad)
{
	int retorno = -1;
	if(this != NULL && localidad != NULL)
	{
		retorno = 0;
		strncpy(localidad,this->localidad,50);
	}
	return retorno;
}

int cartel_setEstadoId(eCartel* this,int estadoId)
{
	int retorno = -1;
	if(this != NULL && estadoId > 0)
	{
		retorno = 0;
		this->estadoId = estadoId;
	}
	return retorno;
}

int cartel_getEstadoId(eCartel* this,int* estadoId)
{
	int retorno = -1;
	if(this != NULL && estadoId != NULL)
	{
		retorno = 0;
		*estadoId = this->estadoId;
	}
	return retorno;
}

int cartel_setMedida(eCartel* this,float medida)
{
	int retorno = -1;
	if(this != NULL && medida >= 0)
	{
		retorno = 0;
		this->medida = medida;
	}
	return retorno;
}
int cartel_getMedida(eCartel* this,float* medida)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		*medida = this->medida;
	}
	return retorno;
}

void cartel_modificacionMedidaPorEstadoId(void* cartel)
{
	eCartel* pCartel=cartel;

	if(pCartel->estadoId==1 && pCartel->medida>=100)
	{
		pCartel->medida=pCartel->medida+10;
	}else if(pCartel->estadoId==2 && pCartel->medida<100)
	{
		pCartel->medida=pCartel->medida+20;
	}
}

int cartel_OrdenamientoPorLocalidad(void* this1, void* this2)
{
	char localidad1[128];
	char localidad2[128];
	cartel_getLocalidad((eCartel*)this1, localidad1);
	cartel_getLocalidad((eCartel*)this2, localidad2);
	if(this1!=NULL && this2!=NULL)
	{
		return strcmp(localidad1, localidad2);
	}
	return 0;
}
void cartel_imprimir(void* cartel)
{
	char estado[128];
	char tipo[128];
	eCartel* auxCartel=cartel;
	if(auxCartel->tipo==1)
	{
		strcpy(tipo, "Venta");
	}else if(auxCartel->tipo==2)
	{
		strcpy(tipo, "Alquiler");
	}
	if(auxCartel->estadoId==1)
	{
		strcpy(estado, "Ofrecido");
	}else if(auxCartel->estadoId==2)
	{
		strcpy(estado, "Alquilado/vendido");
	}
	printf("%d %s %s %s %s %.2f\n",auxCartel->id,tipo,auxCartel->domicilio,auxCartel->localidad,estado, auxCartel->medida);

}

int cartel_cantidadMayorA100(void* element)
{
	eCartel* auxCartel=element;
	if(auxCartel->medida>100)
	{
		return 1;
	}
	return 0;
}

int cartel_cantidadOfrecidos(void* element)
{
	eCartel* auxCartel=element;
	if(auxCartel->estadoId==1)
	{
		return 1;
	}
	return 0;
}
