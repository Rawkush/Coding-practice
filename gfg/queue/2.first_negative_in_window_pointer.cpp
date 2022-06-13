
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


# include <queue>


vector<long long> printFirstNegativeInteger(long long int arr[],
    long long int n, long long int K) {
    queue<long long int> q;
    vector<long long> output;
    
    long long int* i=arr;
    long long int* j= i+(K-1);
    
    
    // for sliding window into queue
    while(i!=j+1){
        
        
        if(*i<0 ){
              q.push(*i);
        }

        i++;
       
    }
    
 q.empty()?output.push_back(0):output.push_back(q.front());
         
     
   
    
    i=arr;
    while(j!=&arr[n-1]){
       
         j=j+1;
        
        if(q.front()==*i++) q.pop();
        
       if(q.empty()){
            if(*j<0){
               q.push(*j);
               output.push_back(*j);
           }
           else output.push_back(0);
       }
       
       else{
            if(*j<0)
               q.push(*j);
           output.push_back(q.front());
       }
 
    }
    return output;
   
 }