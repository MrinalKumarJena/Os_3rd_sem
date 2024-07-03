#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

void main() {
    int num;
    int pid;
    printf("Enter a number: ");
    scanf("%d", &num);

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child Process!");
        if (isPrime(num))
            printf("%d is a prime number\n", num);
        else
            printf("%d is not a prime number\n", num);
    }
    else {

        if (num % 2 == 0)
            printf("%d is an even number\n", num);
        else
            printf("%d is an odd number\n", num);
    }


}
