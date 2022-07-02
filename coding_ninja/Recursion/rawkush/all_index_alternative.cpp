#include<iostream>
using namespace std;


int all(int *a,int s, int *o,int x){
    if(s==0)
        return 0;

    // size of output arrary
    int i= all(a,s-1,o,x);

    if(a[s-1]==x){
        o[i]=s-1;
        return i+1;
    }
    return i;
}

int main(){

    int a[]={5,6,5,5,6};
    int s=5;
    int o[s];
    int tmp=all(a,s,o,5);
    cout<<"size "<<tmp<<endl;
    for(int i=0;i<tmp; i++)
        cout<<o[i]<<endl;


}
