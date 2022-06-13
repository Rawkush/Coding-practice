// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

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



#include<queue>
vector<long long> printFirstNegativeInteger(long long int A[],
    long long int N, long long int K) {

    vector<long long> output;
    queue<long long> q;
    long long int i=0;
    for( i=0; i<K; i++){
        if(A[i]<0){
            q.push(A[i]);
        }
    }

    long long int start =0;
    long long int end = i;
    // adding negative for current window
    if(q.empty()) output.push_back(0);
    else{
        output.push_back(q.front());
    }

    for(i=end;i<N; i++){

        if(A[start++]==q.front()) q.pop();
        if(A[i]<0){
            q.push(A[i]);
        }
        if(q.empty()) output.push_back(0);
        else{
            output.push_back(q.front());
        }
    }
    return output;
 }