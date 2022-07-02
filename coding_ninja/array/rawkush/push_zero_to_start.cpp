#include<iostream>

using namespace std;


//naive implementation
int main(){
    int a[]={2,0, 0, 1, 3, 0, 0};
    for(int i=1;i<7; i++){
        if(a[i]==0){
            int j=i-1;
            while(j>=0 && a[j]>0){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=0;
        }
    }

    for(int i=0; i <7 ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}