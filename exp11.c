#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg)
{
    printf("Thread 1 is executing\n");
    return NULL;
}

void *thread2(void *arg)
{
    printf("Thread 2 is executing\n");
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have finished execution\n");

    return 0;
}
