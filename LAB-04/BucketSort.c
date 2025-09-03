#include <stdio.h>
#include <stdlib.h>
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float buckets[n][n];  
    int count[n];         
    for (int i = 0; i < n; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  
        buckets[index][count[index]++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (count[i] > 0)
            insertionSort(buckets[i], count[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    float a[100];
    int n;
    printf("Enter Size: ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        printf("Enter Element: ");
        scanf("%f",&a[i]);
    }
    bucketSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);

    return 0;
}
