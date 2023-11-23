#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int shared_variable;
    pthread_mutex_t mutex;
} ThreadData;

void *mi_funcion_hilo(void *arg) {
    // Obtener la estructura ThreadData desde el argumento
    ThreadData *thread_data = (ThreadData *)arg;

    // Bloquea el mutex antes de acceder a la variable compartida
    pthread_mutex_lock(&thread_data->mutex);

    // Accede y modifica la variable compartida
    thread_data->shared_variable++;
    printf("Hilo: Variable compartida es %d\n", thread_data->shared_variable);

    // Desbloquea el mutex después de realizar las operaciones críticas
    pthread_mutex_unlock(&thread_data->mutex);

    pthread_exit(NULL);
}

int main() {
    // Inicializa la estructura ThreadData
    ThreadData thread_data;
    thread_data.shared_variable = 0;
    pthread_mutex_init(&thread_data.mutex, NULL);

    pthread_t tid1, tid2;

    // Crea dos hilos y ejecuta la función mi_funcion_hilo con la misma estructura ThreadData
    pthread_create(&tid2, NULL, mi_funcion_hilo, (void *)&thread_data);
    pthread_create(&tid1, NULL, mi_funcion_hilo, (void *)&thread_data);

    // Espera a que ambos hilos terminen (opcional)
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);

    // Destruye el mutex después de su uso
    pthread_mutex_destroy(&thread_data.mutex);

    printf("Fin del programa principal. Variable compartida final: %d\n", thread_data.shared_variable);

    return 0;
}
