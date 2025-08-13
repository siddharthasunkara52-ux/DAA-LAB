#include<stdio.h>

int BinarySearch(int *arr,int left,int right,int s)
{
	if(left<=right)
	{
    int mid;
    mid=(left+right)/2;
    if(arr[mid]==s)
    {
        return mid;
    }
    else if(s<arr[mid])
    {
        return BinarySearch(arr,left,mid-1,s);
    }
    else{
        return BinarySearch(arr,mid+1,right,s);
    }
}
return -1;
}
void main()
{
    int s,n,i,j,arr[100];
    printf("Enter the no.of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    printf("Enter the element to be searched:");
    scanf("%d",&s);

    j=BinarySearch(arr,0,n-1,s);

    if(j!=-1)
    {
    	printf("Element %d is found at index %d",s,j);
	}
	else
	{
		printf("Element %d is not found",s);
	}

}
