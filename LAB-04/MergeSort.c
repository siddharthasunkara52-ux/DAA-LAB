#include<stdio.h>
#define max 100

void merge(int *arr,int l,int mid,int r)
{
    int temp[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;

    
   while(i<=mid && j<=r )
   {
    if(arr[i]<arr[j])
    {
        temp[k++]=arr[i++];
    }
    else{
        temp[k++]=arr[j++];

    }
   }
while(i<=mid)
{
    temp[k++]=arr[i++];
}
while(j<=r)
{
    temp[k++]=arr[j++];
}

for(i=l,k=0;i<=r;i++,k++)
{
    arr[i]=temp[k];
}


}

void MergeSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

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

    MergeSort(arr,0,n-1);

    printf("Elements after Sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

return 0;
    
}
