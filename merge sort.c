#include<stdio.h>

void mergeSort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i,j,k,c[high+1];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while(i<=mid)
    {
        c[k++] = a[i++];
    }
    while(j<=high)
    {
        c[k++] = a[j++];
    }
    for(i = low; i<=high; i++){
        a[i] = c[i];
    }
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
    mergeSort(a,0,n-1);
    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}



/*
Your updated merge sort implementation looks good. The changes you've made ensure that the algorithm works correctly. Here's a brief explanation of the `mergeSort` and `merge` functions:

### `mergeSort` Function:
This function recursively divides the array into two halves until it reaches individual elements (base case where `low >= high`). After dividing, it calls the `merge` function to merge the sorted halves.

### `merge` Function:
This function merges two sorted subarrays into a single sorted array. It uses a temporary array `c` to store the merged elements. Here’s a step-by-step explanation of the `merge` function:

1. **Initialization:**
   - `i` is initialized to `low`, which is the starting index of the left subarray.
   - `j` is initialized to `mid + 1`, which is the starting index of the right subarray.
   - `k` is initialized to `low`, which is the starting index for the merged array in `c`.

2. **Merging:**
   - The `while` loop runs as long as there are elements in both subarrays (`i <= mid` and `j <= high`).
   - If the current element of the left subarray (`a[i]`) is less than the current element of the right subarray (`a[j]`), it is added to the merged array `c`, and `i` is incremented.
   - Otherwise, the current element of the right subarray (`a[j]`) is added to the merged array `c`, and `j` is incremented.

3. **Copying Remaining Elements:**
   - If there are remaining elements in the left subarray, they are copied to `c`.
   - If there are remaining elements in the right subarray, they are copied to `c`.

4. **Copying Back to Original Array:**
   - The merged elements from `c` are copied back to the original array `a` from index `low` to `high`.

### Example Walkthrough:
Let's go through an example with an input array: `[38, 27, 43, 3, 9, 82, 10]`.

1. **Initial Call:**
   - `mergeSort(a, 0, 6)`

2. **First Level of Recursion:**
   - `mergeSort(a, 0, 3)`
   - `mergeSort(a, 4, 6)`

3. **Second Level of Recursion:**
   - For the left half: `mergeSort(a, 0, 1)` and `mergeSort(a, 2, 3)`
   - For the right half: `mergeSort(a, 4, 5)` and `mergeSort(a, 6, 6)`

4. **Third Level of Recursion (Base Case):**
   - For the leftmost part: `mergeSort(a, 0, 0)` and `mergeSort(a, 1, 1)`
   - Then merge: `merge(a, 0, 0, 1)`
   - This process continues until all subarrays are merged.

5. **Final Merged Array:**
   - After merging all subarrays step-by-step, the final sorted array is: `[3, 9, 10, 27, 38, 43, 82]`

Here's your corrected and fully functional code:

```c
#include <stdio.h>

void mergeSort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int c[high + 1]; // Temp array to store merged elements

    i = low; // Starting index for left subarray
    j = mid + 1; // Starting index for right subarray
    k = low; // Starting index to be sorted

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= high) {
        c[k++] = a[j++];
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
```

This code will correctly perform the merge sort and print the sorted array.
*/
