#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void* thread_function(void *arg) {
    printf("Hilo creado en el proceso: %d\n", getpid());
}

int main() {
    pid_t pid;
    pthread_t thread_id;

    printf("Proceso inicial PID: %d, padre: %d\n", getpid(),getppid());

    pid = fork();
    if (pid == 0) { // Proceso hijo
        printf("Proceso hijo PID: %d, padre PID: %d\n", getpid(), getppid());

        pid_t hijo = fork();
        if (hijo == 0) { // Hijo del hijo
            printf("Proceso nieto PID: %d, padre PID: %d\n", getpid(), getppid());
        }

        pthread_create(&thread_id,NULL,thread_function,NULL);

    } else {
        //printf("H. Soy padre %d, padre: %d\n",getpid(),getppid());
        wait(NULL);
    }

    // El proceso padre original, el primer hijo y el hijo del hijo pasan por aca
    pid = fork();
    if (pid == 0) { // Nuevo proceso hijo
        printf("Proceso hijo PID: %d, padre PID: %d\n", getpid(), getppid());
    } else {
        wait(NULL);
    }

    return 0;
}