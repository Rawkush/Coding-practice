//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
   public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high) return;
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
 
    }
    

    public:
    int partition (int arr[], int low, int high)
    {
       if(low>= high) return low;
       // here l= pivot
       int l = low+1;
       int h= high;
       int pivot = low;
       while(l<=h){
            while(arr[l]<=arr[pivot] ) l++;  
            while(arr[h]>arr[pivot] ) h--;
            if(l<h)  swap(arr[l], arr[h]);
       }
       swap(arr[pivot], arr[h]);
       return h;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends