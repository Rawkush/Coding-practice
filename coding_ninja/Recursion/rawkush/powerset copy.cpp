#include<iostream>
using namespace std;

int powset(int *a, int output[][1000], int si){
    if(si==0){
        output[0][0]=0;
        return 1;
    }

    int s= powset(a+1, output,si-1);
    for(int i=0;i<s;i++){
        int count=output[i][0];
        output[i+s][0]=output[i][0]+1;
        output[i+s][1]=a[0];
        for(int j=0; j<count;j++){
            output[i+s][j+2]=output[i][j+1];
        }
    }

    return 2*s;
}

int main(){

    int a[]={1,2,3};
    int out[1000][1000];

    int count=powset(a,out, 3);
    for(int i=0;i<count;i++){
        for(int j=1; j<=out[i][0];j++)
            cout<<out[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
