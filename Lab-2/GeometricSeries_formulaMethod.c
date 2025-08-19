#include <stdio.h>
#include <math.h>

int main()
{
    int  n;
    float r;
    double sum;

    printf("Enter Total number of terms : ");
    scanf("%d", &n);

    printf("Enter the common ratio (r): ");
    scanf("%f", &r);
    if (r == 1)
    {
        sum = n ;
    }
    else
    {
        sum = (1 - pow(r, n )) / (1 - r);  
    }

    printf("Sum of the Series = %.2f\n", sum);
    return 0;
}
