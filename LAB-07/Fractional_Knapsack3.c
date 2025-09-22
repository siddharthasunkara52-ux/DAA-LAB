 #include<stdio.h>
typedef struct
{   int weight;
    int profit;
    float ratio;
}Item;

void merge(Item *arr,int l,int mid,int r)
{
    Item temp[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;

    
   while(i<=mid && j<=r )
   {
    if(arr[i].ratio>arr[j].ratio)
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

void MergeSort(Item *arr,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }
}

double Fractional_Knapscak3(int capacity,Item * items,int n)
{
    double totalProfit=0;
   
    for(int i=0;i<n;i++)
    {
        if(items[i].weight<=capacity)
        {
            capacity-=items[i].weight;
            totalProfit+=items[i].profit;
         }
        else
        {
            totalProfit+=items[i].profit*((double)capacity/items[i].weight);
           
            break;
        }

       
    }
    
     return totalProfit;
}

 int main()
 {
    int capacity,n;

    printf("Enter the Capacity of Knapsack:");
    scanf("%d",&capacity);
    printf("\nEnter no.of Items:");
    scanf("%d",&n);
    Item items[n];
   
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the weight and profit of Item %d :",i+1);
        scanf("%d %d",&items[i].weight,&items[i].profit);
        items[i].ratio=(float)items[i].profit/items[i].weight;
    }
    MergeSort(items,0,n-1);
    printf("---Sorted Items(decending oder) by their profit/weight ratio---\n");
    printf("Weight\tProfit\tRatio\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%.2f\n",items[i].weight,items[i].profit,items[i].ratio);
    }
   
    double total3=Fractional_Knapscak3(capacity,items,n);

 
 printf("\nTotal Profit is(BY METHOD 3):%.2f",total3);

   return 0;
 }
 