//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int left = 0;
	    int right = n-1;
	    
	    if(n<=1) return 0;
	    if(arr[0]<arr[n-1]){
	        return 0; 
	    }
	    while(left<right){
	        int mid = left+ (right-left)/2;
	        int prev = (mid+n-1)%(n); // %n makes sure prev index lies between 0-n, 
	        /**
	         * if prev is less than 0, then next previous should be index n, 
	         */
	        int next = (mid+1)%(n);
            if(arr[mid]<arr[prev] && arr[mid]<arr[next]){
                return mid;
            }else 
            //unsorted
            if(arr[mid]<arr[right]){
                right =mid-1;
            }
            else
            //unsorted
            {
                left = mid+1;
            }
	    }
	    
	    return left;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends