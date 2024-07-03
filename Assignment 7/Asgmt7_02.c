#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
char str[1024];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int no_read = 0, no, sum = 0;
pthread_cond_t cond;
void *read()
{
    while (1)
    {
        while (no_read)
            ;
        pthread_mutex_lock(&lock);
        printf("\nEnter a no:");
        scanf("%d", &no);
        no_read = 1;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond);
    }
}
void *SquareSum()
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        while (!no_read)
            pthread_cond_wait(&cond, &lock);
        sum += no * no;
        printf("\nSum is : %ds\n", sum);
        no_read = 0;
        pthread_mutex_unlock(&lock);
    }
}
int main()
{
    pthread_t tr, tw;
    pthread_create(&tr, NULL, read, NULL);
    pthread_create(&tw, NULL, SquareSum, NULL);
    pthread_join(tr, NULL);
    pthread_join(tw, NULL);
}
