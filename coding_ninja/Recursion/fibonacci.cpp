#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// to get fibo no. not sequence
int fibo(int n){
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    return fibo(n-1)+ fibo(n-2);

}

int main() {
    int n=7;
    for(int i=0; i<n;i++)
        cout<<fibo(i)<<" ";
}
