//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x) {
        // code here
        int left =0;
        int right =n;
        int leftMostIndex = 0;
        int rightMostIndex=-1;
        
        while(left<=right){
            int mid = left+ ( right- left)/2;
            if(arr[mid]==x){
                leftMostIndex = mid;
                right =mid-1;
            }else
            if(arr[mid]>x){
                right =mid-1;
            }else
            if(arr[mid]<x){
                left = mid+1;
            }
        }
        
        left = 0;
        right =  n;
        while(left<=right){
            int mid = left+ ( right- left)/2;
            if(arr[mid]==x){
                rightMostIndex = mid;
                left =mid+1;
            }else
            if(arr[mid]>x){
                right =mid-1;
            }
            else
            if(arr[mid]<x){
                left = mid+1;
            }
        }
        return rightMostIndex - leftMostIndex +1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends