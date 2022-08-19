//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>
// Brute Force
long long int countBT(int h){
  if (h <= 1)
    return 1;
  long mod = (int)pow(10, 9) + 7;
  long long x = countBT(h - 1);
  long long y = countBT(h - 2);
  long long tmp1 = (long long) ((long long)(x)*x)%mod;
  long long tmp2 =(long long) (2*(long long)(x)*y)%mod;
  long long ans = tmp1 + tmp2 %mod;
  return ans;
}


// memorization
long long int countBTHelper(int h, unordered_map<int, long long int>& mem){
  if (h <= 1)
    return 1;
  if(mem.find(h) != mem.end()) return mem[h];
  long mod = (int)pow(10, 9) + 7;
  long long x = countBTHelper(h - 1, mem);
  long long y = countBTHelper(h - 2, mem);
  long long tmp1 = (long long) ((long long)(x)*x)%mod;
  long long tmp2 =(long long) (2*(long long)(x)*y)%mod;
  long long ans = (tmp1 + tmp2) %mod;
  mem[h]=ans;
  return mem[h];
}

long long int countBT(int h){
  unordered_map<int, long long int> mem;
  return countBTHelper(h, mem);
}


// DP

long long int countBT(int h){
  long long int mem[h+1];
  mem[0]=1;
  mem[1]=1;
  long mod = (int)pow(10, 9) + 7;
  for(int i=2; i<=h; i++){
    // mem[i] = (mem[i-1] + mem[i-2])%mod;
    long long int x= mem[i-1];
    long long int y =mem[i-2];
    long long int tmp1 = ((long long)(x)*x)%mod;
    long long int tmp2= (2*(long long)(y)*x)%mod;
    mem[i] = (tmp1+tmp2)%mod;
  }
  return mem[h];
}
