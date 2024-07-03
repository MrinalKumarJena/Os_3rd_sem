#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
int CurrentID = 1;
void *function(void *n)
{
    char *s = (char *)n;
    int ownID = *((int *)s) + 1;
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mut);
        printf("\nCurrent ID=%d, OwnID=%d", CurrentID, ownID);
        if (CurrentID == ownID)
        {
            printf("\nMy Turn. Thread ID=%ld", pthread_self());
            CurrentID++;
            if (CurrentID == 5)
                CurrentID = 1;
        }
        else
            printf("\nNot My Turn. Thread ID=%ld", pthread_self());
        pthread_mutex_unlock(&mut);
    }
}
int main()
{
    pthread_t tid[5];

    int i, *p;
    char str[10];
    for (i = 0; i < 5; i++)
    {
        p = &i;
        pthread_create(&tid[i], NULL, function, (void *)p);
    }
    for (i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);
}
