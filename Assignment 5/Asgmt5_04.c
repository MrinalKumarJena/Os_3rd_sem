#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main(){
        int pid = fork();

        if(pid<0){
                printf("Fork Failed");
        }
        else if(pid==0){
                printf("\nChild Ends\n");
                printf("PArent Ends\n");
        }
        else{
                printf("Child Starts\n");
                 for(int i=1;i<=10;i++){
                        printf("%d ",i);
                }

        }
}
