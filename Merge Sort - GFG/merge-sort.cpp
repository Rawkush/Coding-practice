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
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
     auto *la = new int[m - l+1];
     auto *ra =  new int[r-m];
     int li =0, ri=0;
     int ls = m-l+1;
     int rs = r-m;
     int idx=l;
     
     //initialize the smaller arrays
     while(li<ls){
         la[li] = arr[l+li];
         li++;
     }
     while(ri<rs){
         ra[ri] = arr[m+ri+1];
         ri++;
     }
     li=0;
     ri=0;
     while(li< ls && ri< rs){
         if(la[li]<ra[ri]){
             arr[idx++] = la[li++];
         }else{
             arr[idx++] = ra[ri++];
         }
     }
     
     while(ri<rs){
         arr[idx++] = ra[ri++];
     }
     while(li<ls){
         arr[idx++] = la[li++];
     }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r) return;
        int mid = l +(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends