#include<stdio.h>

int partition(int a[], int low, int high);

void quickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid = partition(a,low,high);
        quickSort(a,low,mid-1);
        quickSort(a,mid+1,high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low+1;
    int j = high;
    while(i<=j)
    {
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
