#include<stdio.h>

int main()
{
    int n,i;
    float r;
    double sum=0,a=1;
     printf("Enter Total number of terms : ");
    scanf("%d", &n);

    printf("Enter the common ratio (r): ");
    scanf("%f", &r);
    for(i=0;i<n;i++)
    {
        sum=sum+a;
        a=a*r;
    }
     printf("Sum of the Series = %.2f\n", sum);
}
