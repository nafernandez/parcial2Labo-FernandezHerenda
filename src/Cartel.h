/*
 * Cartel.h
 *
 *  Created on: 30 jul. 2020
 *      Author: natyf
 */

#ifndef CARTEL_H_
#define CARTEL_H_
typedef struct{
	int id;
	int tipo;
	char domicilio[128];
	char localidad[128];
	int estadoId;
	float medida;
	}eCartel;

eCartel* cartel_new(void);
eCartel* cartel_newParametros(char*id, char* tipo,char* domicilio,char* localidad, char* estadoId, char* medida);
void cartel_delete(eCartel* this);

int cartel_setId(eCartel* this,int id);
int cartel_getId(eCartel* this,int* id);
int cartel_setTipo(eCartel* this,int tipo);

int cartel_getTipo(eCartel* this,int* tipo);

int cartel_setDomicilio(eCartel* this,char* domicilio);

int cartel_getDomicilio(eCartel* this,char* domicilio);
int cartel_setLocalidad(eCartel* this,char* localidad);

int cartel_getLocalidad(eCartel* this,char* localidad);

int cartel_setEstadoId(eCartel* this,int estadoId);

int cartel_getEstadoId(eCartel* this,int* estadoId);


int cartel_setMedida(eCartel* this,float medida);

int cartel_getMedida(eCartel* this,float* medida);
int cartel_OrdenamientoPorLocalidad(void* this1, void* this2);
void cartel_imprimir(void* cartel);
void cartel_modificacionMedidaPorEstadoId(void* cartel);
int cartel_cantidadMayorA100(void* element);
int cartel_cantidadOfrecidos(void* element);
#endif /* CARTEL_H_ */
