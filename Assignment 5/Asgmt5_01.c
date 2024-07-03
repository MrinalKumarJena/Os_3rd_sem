#include <stdio.h>
#include <unistd.h>
void main()
{
        printf("WelCome\n");
        fork();
        printf("\nHello World\n");
        int  pid;
        pid = getpid();
        printf("Process Id = %d \n",pid);
        int ppid;
        ppid=getppid();
        printf("Parent process Id=%d \n",ppid);


}
