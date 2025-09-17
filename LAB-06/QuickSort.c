#include<stdio.h>

int partioning(int *arr,int l,int r)
{
    int pivot=arr[l];
    int i=l+1;
    int j=r,temp;
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
            i++;
            j--;
        }

    }
    temp = arr[l];
  arr[l] = arr[j];
   arr[j] = temp;

    return j;
    
}
void QuickSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int p=partioning(arr,l,r);
        QuickSort(arr,l,p-1);
        QuickSort(arr,p+1,r);
    }
}
int main()
{
    int n;
    printf("Enter no.of Elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nElements before sorting:");
    for(int i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
    QuickSort(arr,0,n-1);
     printf("\nElements after sorting:");
    for(int i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
return 0;

}
