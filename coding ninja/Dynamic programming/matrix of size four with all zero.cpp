#include<iostream>
using namespace std;


bool check(int *a, int n, int m, int i){



}

int getMax(int *a, int n, int m){
    int t= max(n,m);
    int max_size=0;
    for(int i=0; i<t; i++){
        if(check(a,n,m,i))
            max_size=i;
    }
    return max_size;
}

int main(){
    int a[][]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    cout<<getmax(a,4,4);
}
