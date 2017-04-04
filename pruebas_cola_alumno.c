#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void crear_y_eliminar_cola(void){
    printf("PRUEBA 1: Crear y eliminar una cola (cola1).\n");
	cola_t* cola1 = cola_crear();
    print_test("-La cola se creo vacia", cola_esta_vacia(cola1) == 1);
    print_test("-Ver primer elemento de una cola vacia", cola_ver_primero(cola1) == NULL);
    cola_destruir(cola1, NULL);
    print_test("-Elimino la cola", true);
    printf("\n");
}
    
void encolar_y_desencolar_elementos(void){
	printf("PRUEBA 2: Encolar elementos (cola2).\n");
	cola_t* cola2 = cola_crear();
    int a[1];
    int b[2];
    int c[3];
    int d[4];
    int e[5];
    print_test("-Encolar un elemento", cola_encolar(cola2, a) == true);
    print_test("-Encolar un elemento", cola_encolar(cola2, b) == true);
    print_test("-Encolar un elemento", cola_encolar(cola2, c) == true);
    print_test("-Encolar un elemento", cola_encolar(cola2, d) == true);
    print_test("-Encolar un elemento", cola_encolar(cola2, e) == true);
    print_test("-Al ver el primero, los elementos coinciden", cola_ver_primero(cola2) == a);
    printf("\n");
    printf("PRUEBA 3: Desencolar elemenos (cola2).\n");
    while(!cola_esta_vacia(cola2)){
		print_test("Desencolo un elemento", cola_desencolar(cola2) != NULL);
	}
	print_test("-La cola ciertamente se encuentra vacia", cola_esta_vacia(cola2) == 1);
	cola_destruir(cola2, NULL);
	print_test("-Elimino la cola", true);
	printf("\n");
}

void probar_comportamiento_muchos_elementos(void){
	printf("PRUEBA 4: Lleno la cola con 1000 elementos (cola3)\n");
	cola_t* cola3 = cola_crear();
	int vec[1000];
	for(int i = 0; i<=1000; i++){
		cola_encolar(cola3, &vec[i]);
	}
	print_test("-La cola no esta vacia",cola_esta_vacia(cola3) == 0);
	while (!cola_esta_vacia(cola3)){
		cola_desencolar(cola3);
	}
	print_test("-Al vaciar la cola, ciertamente se encuentra vacia", cola_esta_vacia(cola3) == 1);
	cola_destruir(cola3, NULL);
	print_test("-Elimino la cola", true);
	printf("\n");
}
	
void pruebas_cola_alumno(){
	crear_y_eliminar_cola();
	encolar_y_desencolar_elementos();
	probar_comportamiento_muchos_elementos();
}
