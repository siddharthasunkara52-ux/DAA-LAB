#include<stdio.h>
#include"StackADT.h"

int main()
{
    int x,y;
    stack s;
    initstack(&s);
    push(&s,2);
    push(&s,5);
    push(&s,7);
    push(&s,9);
    display(&s);
    x= pop(&s);
   printf("\nPopped Element:%d\n",x);
   y= peak(&s);
  printf("Peak Element:%d",y);
  display(&s);
  return 0;
}
