#include <iostream>
using namespace std;

 void merge(int *arr,int l, int m, int r){

    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;
// Initial index of merged subarray
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

/* UTILITY FUNCTIONS */
/* Function to print an array */

void mergeSort(int *arr, int l, int r){
    if(l>=r)
        return; //already sorted
    if(l-r==1){
        if(arr[l]>arr[r]){
            int tmp = arr[l];
            arr[l]=arr[r];
            arr[r]= tmp;
        }
        //else already sorted
        return; //
    }
    int mid= (l+r)/2;
    mergeSort(arr, l,mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid,r);
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{

    int a[]={1,9,2,5,3,4};
    mergeSort(a,0,5);
    printArray(a,5);
    return 0;
}
