// multiple stack
// 17 feb 2025
// #define -- pre processor directive -- macros define / create 

#include<stdio.h>
#define MAX 100

int stack[MAX], top1 = -1, top2 = MAX ;

int isstack1empty (){return (top1 == -1) ? 1:0 ; }
int isstack2empty (){return (top2 == MAX) ? 1:0 ;}

int isstack1full(){return (top1 == top2 - 1)? 1:0}
int isstack2full(){return (top2 == top1 + 1)? 1:0}

void pushstack1(int data){
    if(isstack1full())
    printf("Stack 1 is full\n"); 
    else {
        stack[++top1] = data; printf("element added\n")
    }
}
void pushstack2(int data){
    if(isstack2full())
    printf("Stack 2 is full\n"); 
    else {
        stack[--top2] = data; printf("element added\n")
    }
}
void popstack1(){
    if(isstack1empty())
    printf("Stack 1 is empty\n");
    else {
        printf("popped element is %d\n", stack[top1--]);
    }
}
void popstack2(){
    if(isstack2empty())
    printf("Stack 2 is empty\n");
    else {
        printf("popped element is %d\n", stack[top2++]);
    }
}

void peekstack1(){
    if(isstack1empty())
    printf("stack 1 is empty");
    else{
        return stack1[top1];
    }
}
void peekstack2(){
    if(isstack2empty())
    printf("stack 2 is empty");
    else{
        return stack2[top2];
    }
}

void showstack1()
{
    if (isemptystack1())
    {
        printf("Stack 1 is empty!\n");
    }
    else
    {
        printf("Stack 1 elements are:\n");
        for (int i = top1; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void showstack2()
{
    if (isemptystack2())
    {
        printf("Stack 2 is empty!\n");
    }
    else
    {
        printf("Stack 2 elements are:\n");
        for (int i = top2; i < MAX ; i++)
        {
            printf("%d\n", stack2[i]);
        }
    }
}