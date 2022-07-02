#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}
int partition(int *arr, int low, int high){
    int pivot=arr[high];
    int i,j;
    j=low; //this keeps track of position where smaller element should come
    for(i=low;i<high;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[j++]);
        }
    }
    //j+1  will be the position where our pivot should be
    swap(arr[i],arr[j]);
    return j;
}


void quickSort(int *arr, int low, int high){
    if(low >= high) return;
    int partition_index = partition(arr,low, high);
    //we do this for partition-1 as partition_index already have pivot in its correct position
    quickSort(arr, low, partition_index-1);
    quickSort(arr,  partition_index+1, high);
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
    printArray(a,5);
    quickSort(a,0,5);
    printArray(a,5);
    return 0;
}
