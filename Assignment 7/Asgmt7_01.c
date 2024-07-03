#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *odd_even(void *ptr);
void *prime(void *ptr);
int main()
{
    int iret1, iret2, *number;
    pthread_t thread1, thread2;
    printf("enter the number\n");
    number = (int *)malloc(4);
    scanf("%d", number);
    iret1 = pthread_create(&thread1, NULL, odd_even, (void *)number);
    iret2 = pthread_create(&thread2, NULL, prime, (void *)number);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    exit(0);
}
void *odd_even(void *ptr)
{
    int *no;
    no = (int *)ptr;
    if (*no % 2 == 0)
        printf("\n%d is an even number\n", *no);
    else
        printf("\n%d is an odd number\n", *no);
    sleep(3);
}
void *prime(void *ptr)
{
    int i = 1, n = 0, *no;
    no = (int *)ptr;
    while (i <= *no)
    {
        if (*no % i == 0)
            n++;
        i++;
    }
    if (n == 2)
    {
        printf("\n%d is a prime number\n", *no);
    }
    else
        printf("\n%d is not a prime number\n", *no);

    sleep(3);
}
