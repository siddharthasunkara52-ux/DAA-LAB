#include<stdio.h>
#define max 100
typedef struct  stack
{
    int arr[100];
    int top;

}stack;
void initstack(stack * s)
{
    s->top=-1;
}
int isempty(stack *s)
{ 
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(stack * s)
{
    if(s->top==max-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack * s,int x)
{
    if(isfull(s))
    {
        printf("Stack is Full\n");
    }
    else{
        s->top++;
        s->arr[s->top]=x;
    }
}
int pop(stack * s)
{
    if(isempty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        int x=s->arr[s->top];
        s->top--;
        return x;
    }
}

int peak(stack *s)
{
    if(isempty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        return s->arr[s->top];
    }
}
void display(stack *s)
{
    if(isempty(s))
    {
        printf("Stack is Empty\n");
       
    }
    else{
        printf("\nStack Elements are:");
        for(int i=s->top;i>=0;i--)
        {
            printf("%d ",s->arr[i]);
        }
    }
}
