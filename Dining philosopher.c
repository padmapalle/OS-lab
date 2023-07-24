/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Think
        printf("Philosopher %d is thinking\n", philosopher_id);

        // Wait for forks
        sem_wait(&forks[left_fork]);
        printf("Philosopher %d picked up fork %d (left)\n", philosopher_id, left_fork);
        sem_wait(&forks[right_fork]);
        printf("Philosopher %d picked up fork %d (right)\n", philosopher_id, right_fork);

        // Eat
        printf("Philosopher %d is eating\n", philosopher_id);
        sleep(2);

        // Release forks
        sem_post(&forks[left_fork]);
        printf("Philosopher %d put down fork %d (left)\n", philosopher_id, left_fork);
        sem_post(&forks[right_fork]);
        printf("Philosopher %d put down fork %d (right)\n", philosopher_id, right_fork);
    }

    return NULL;
}

int main() {
    int i;
    int philosopher_ids[NUM_PHILOSOPHERS];

    // Initialize the forks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // Wait for the threads to finish (this won't happen since philosophers run forever)
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy the forks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
