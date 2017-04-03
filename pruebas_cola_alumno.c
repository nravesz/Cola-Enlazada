#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_cola_alumno(){
	
    printf("PRUEBA 1: Crear y eliminar una cola.\n");
	
	cola_t* cola1 = cola_crear()
	
    print_test("-La cola se creo vacia", cola_esta_vacia(cola1) == 1);
    print_test("-Ver primer elemento de una cola vacia", cola_ver_primero(cola1) == NULL);
    cola_destruir(cola1, NULL))
    print_test("-Elimino la cola", true);
    printf("\n")
    
	printf("PRUEBA 2: Encolar elementos.\n");
	
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
    print_test("-Al ver el primero, los elementos coinciden", cola_ver_primero(cola1) == a);
    printf("\n")
    
    printf("PRUEBA 3: Desencolar elemenos.\n")
    
    while(!cola_esta_vacia(cola2)){
		print_test("Desencolo un elemento", cola_desencolar(cola2) == true);
	print_test("-La cola ciertamente se encuentra vacia", cola_esta_vacia(cola2) == 1);
	cola_destruir(cola2, NULL);
	print_test("-Elimino la cola", true);
	printf("\n");
