#include<iostream>
using namespace std;

int main(){
    int n=4;
    for(int i=0; i<n ; i++){
        int count=i;
        for(int j=0 ; j<n+i; j++){
          if(j<n-i-1){
            cout << " ";
          }else{
              if(j>=n){
                  cout << --count;
              }else
            cout<<++count;
          }
        }
        cout<<endl;
    }
    return 0;
}