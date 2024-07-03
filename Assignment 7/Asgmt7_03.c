#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *block1(void *ptr);
void *block2(void *ptr);
int mat1[] = {1, 2, 3, 4, 5};
int mat2[] = {1, 2, 3, 4, 5}, res[5];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void sum(int i)
{
    pthread_mutex_lock(&mutex1);
    res[i] = mat1[i] * mat2[i];
    pthread_mutex_unlock(&mutex1);
}
int main()
{
    int iret1, iret2, *number, s = 0, i;
    pthread_t thread1, thread2;
    /*printf("enter the size of vector\n");
    scanf("%d",&p);
    printf("enter the value of 1 st vector");
    for(i=0;i<p;i++)
    scanf("%d",&mat1[i]);
    printf("enter the value of 2nd vector");
    for(i=0;i<p;i++)
    scanf("%d",&mat2[i]);*/
    number = (int *)malloc(sizeof(int));
    *number = 5;
    iret1 = pthread_create(&thread1, NULL, block1, (void *)number);
    iret2 = pthread_create(&thread2, NULL, block2, (void *)number);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    for (i = 0; i < *number; i++)
    {
        s = s + res[i];
        printf("%d\t", res[i]);
    }
    printf("\nsum of product of two vectors is %d\n", s);
    exit(0);
}
void *block2(void *ptr)
{
    int *no, i;
    no = (int *)ptr;
    int n = *no;
    for (i = n / 2; i < n; i++)
        sum(i);
    sleep(2);
}
void *block1(void *ptr)
{

    int *no, i;
    no = (int *)ptr;
    int n = *no;
    for (i = 0; i < n / 2; i++)
        sum(i);
    sleep(2);
}
