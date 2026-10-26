/*
 * EX NO 7 - Part B: Deadlock avoidance (both trains lock tracks in the same order)
 * Compile: gcc ex7_partB_deadlock_avoidance.c -o avoidance -pthread
 * Run    : ./avoidance   (enter two train IDs, e.g. 1 2)
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t t0, t1;

void *train(void *id) {
    int tid = *(int*)id;
    pthread_mutex_lock(&t0);
    sleep(1);
    pthread_mutex_lock(&t1);
    printf("Train %d crossed safely\n", tid);
    pthread_mutex_unlock(&t1);
    pthread_mutex_unlock(&t0);
    return NULL;
}

int main() {
    int x, y;
    printf("Enter Train IDs: ");
    scanf("%d %d", &x, &y);
    pthread_t a, b;
    pthread_mutex_init(&t0, NULL);
    pthread_mutex_init(&t1, NULL);
    pthread_create(&a, NULL, train, &x);
    pthread_create(&b, NULL, train, &y);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    printf("No deadlock occurred\n");
    return 0;
}
