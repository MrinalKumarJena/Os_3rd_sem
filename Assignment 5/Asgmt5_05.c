#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main(){
        int pid = fork();

        if(pid<0){
                printf("Fork Failed");
        }
        else if(pid==0){
                printf("\nChild Starts\n");
                for(int i=1;i<=10;i++){
                       printf("%d ",i);
                }
                printf("\nChild Ends\n");
        }
        else{
                printf("Parent Starts\n");
                 for(int i=1;i<=10;i++){
                        printf("%d ",i);
                }
                printf("\nParent Ends");

        }
}
