#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int fact(int n){
    if(n<=1)
        return 1;
    return n*fact(n-1);
}

int main() {
    int n=3;
    //cin>>n;
    cout<<"my oput "<< fact(n);
}
