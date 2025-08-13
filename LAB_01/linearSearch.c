#include<stdio.h>

int linearSearch(int *arr,int n,int s)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==s)
        {
            break;
        }
    }
    if(i<n)
    {
        return i;
    }
    else{
        return -1;
    }
}



void main()
{
    int arr[100],n,i,s;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&s);
    i=linearSearch(arr,n,s);
    if(i!=-1)
    {
      	printf("Element %d is found at index %d",s,i);
	}
	else
	{
		printf("Element %d is not found",s);
	}

}
