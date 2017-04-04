#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

/* *****************************************************************
 *                    ESTRUCTURA DE LA COLA
 * *****************************************************************/

typedef struct nodo{
	void* dato;
	struct nodo* prox;
} nodo_t;

struct cola{
	nodo_t *prim;
	nodo_t *ult;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

nodo_t* crear_nodo();

cola_t* cola_crear(void){
	cola_t* cola = malloc(sizeof(cola_t));
	if (cola == NULL){
		return NULL;
	}
	cola->prim = NULL;
	cola->ult = NULL;
	return cola;
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)){
	nodo_t* nodo = cola->prim;
	while(nodo != NULL){
		nodo_t* aux = nodo->prox;
		if (destruir_dato != NULL){
			destruir_dato(nodo->dato);
		}
		free(nodo);
		nodo = aux;
	}
	free(cola);
}

bool cola_esta_vacia(const cola_t *cola){
	if (cola->prim == NULL){
		return true;
	}
	return false;
}

bool cola_encolar(cola_t *cola, void* valor){
	nodo_t* nodo = crear_nodo();
	if (nodo == NULL){
		return false;
	}
	nodo->dato = valor;
	if (cola->prim == NULL){
		cola->prim = nodo;
		cola->ult = nodo;
		return true;
	}
	(cola->ult)->prox = nodo;
	cola->ult = nodo;
	return true;
}

void* cola_ver_primero(const cola_t *cola){
	if (cola->prim == NULL){
		return NULL;
	}
	return (cola->prim)->dato;
}

void* cola_desencolar(cola_t *cola){
	if (cola->prim == NULL){
		return NULL;
	}
	void* valor = (cola->prim)->dato;
	if ((cola->prim)->prox == NULL){
		free(cola->prim);
		cola->prim = NULL;
		cola->ult = NULL;
	}
	else{
		nodo_t* aux = (cola->prim)->prox;
		free(cola->prim);
		cola->prim = aux;
	}
	return valor;
}


/* Funciones auxiliares :)*/
nodo_t* crear_nodo(){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (nodo == NULL){
		return NULL;
	}
	nodo->dato = NULL;
	nodo->prox = NULL;
	return nodo;
}
	
