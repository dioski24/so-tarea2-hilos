/*
 * Tarea 2 - Creacion de un hilo con la biblioteca pthread
 * El hilo principal (main) imprime del 1 al 10000.
 * El hilo creado imprime del 10000 al 1.
 */
#include <stdio.h>      /* printf, fprintf */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <string.h>     /* strerror */
#include <pthread.h>    /* pthread_* */

#define LIMITE 10000

/* Funcion que ejecuta el hilo secundario */
void *contar_descendente(void *arg)
{
    int i;
    (void)arg;   /* No usamos el argumento */

    for (i = LIMITE; i >= 1; i--) {
        printf("Hilo secundario: %d\n", i);
    }
    pthread_exit(NULL);   /* Termina el hilo */
}

int main(void)
{
    pthread_attr_t tattr;   /* atributos de los hilos */
    pthread_t tid;          /* descriptor de hilo     */
    int rc, i;

    /* Establecer los atributos (como en la diapositiva 40) */
    pthread_attr_init(&tattr);
    pthread_attr_setscope(&tattr, PTHREAD_SCOPE_SYSTEM);

    /* Crear el hilo: empieza a ejecutar contar_descendente(NULL) */
    rc = pthread_create(&tid, &tattr, contar_descendente, NULL);
    if (rc != 0) {
        fprintf(stderr, "Error en pthread_create: %s\n", strerror(rc));
        exit(EXIT_FAILURE);
    }

    /* Mientras tanto, el hilo principal cuenta hacia arriba */
    for (i = 1; i <= LIMITE; i++) {
        printf("Hilo principal: %d\n", i);
    }

    /* Esperar a que el hilo secundario termine */
    pthread_join(tid, NULL);
    pthread_attr_destroy(&tattr);

    printf("Ambos hilos terminaron.\n");
    return 0;
}
