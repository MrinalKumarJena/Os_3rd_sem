//shortest job first
#include<stdio.h>
void sjf(){
input();
sort();
}
void sort(int a[]){
int x= sizeof(a)/sizeof(int);
for(int i=0;i<x;i++){
for(int j=1;i<x;j)