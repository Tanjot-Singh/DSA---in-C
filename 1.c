#include<stdio.h>
void change(int *x){
    (*x)++;
}
int main(){
    int x = 10; 
    
    change(&x);
    printf("x= %d\n",x);
    return 0 ;
}

//https://www.hackerrank.com/contests/ds-coding-contest