#include <bits/stdc++.h>
using namespace std;


// Brute force
int MinSquares(int n){
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int minSq = INT_MAX;
  for (int i = 1; i * i <= n; i++){
    minSq = min(minSq, MinSquares(n - i * i));
  }
  return minSq + 1;
}

// with memoization
int MinSquaresWithMemo(int n, int *arr){
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if(arr[n]!=-1) return arr[n];
  int minSq = INT_MAX;
  for (int i = 1; i * i <= n; i++){
    minSq = min(minSq, MinSquaresWithMemo(n - i * i, arr));
  }
  arr[n]= minSq+1;
  return arr[n];
}

int MinSquares(int n){
  int *arr= new int[n+1];
  for(int i=0; i<n+1; i++) arr[i]=-1;
  return MinSquaresWithMemo(n, arr);
}

//USING Dynamic Programming
int MinSquares(int n){
  int arr[n+1];
  arr[0]= 0;
  arr[1]=1;
  for(int i=2; i<=n; i++){
    arr[i]= INT_MAX;
    for(int j=1; i-j*j>=0; j++){
      arr[i] = min(arr[i], arr[i-j*j]+1);
    }
  }
  return arr[n];
}


//{ Driver Code Starts.
int main()
{

  int ans = MinSquares(6);
  cout << ans << "\n";

  return 0;
}
// } Driver Code Ends