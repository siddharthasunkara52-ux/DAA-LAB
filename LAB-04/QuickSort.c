#include<stdio.h>
#define max 100

int partison(int * arr,int l,int r)
{
    int pivot=arr[l];
    int i=l+1;
    int j=r;
    int temp;


while(i<=j)
{
    while(arr[i]<pivot && i<=r)
    {
        i++;
    }
    while(arr[j]>pivot && j>=l)
    {
        j--;
    }
    if(i<j)
    {
         temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }


}

temp=pivot;
arr[l]=arr[j];
arr[j]=pivot;
return j;


}
void QuickSort(int * arr,int l,int r)
{
    if(l<r)
    {
        int p=partison(arr,l,r);
        QuickSort(arr,l,p-1);
        QuickSort(arr,p+1,r);
    }
}


int main()
{
    int arr[max];
    int n,i;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    QuickSort(arr,0,n-1);

    printf("Elements after Sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

return 0;
    
}
