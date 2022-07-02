#include<iostream>
using namespace std;


// int all(int *a,int s, int *o,int x){
//     if(s==0)
//         return 0;

//             // size of output arrary

//     if(a[0]==x){
//         int tmp=0;
//         int p;
//         for(int j=0;j<=i;j++){
//             p=o[j];
//             o[j]=tmp;
//             tmp=p+1;
//         }
//         return i+1;
//     }else
//         for(int j=0;j<i;j++){
//             o[j]++;
//     }

//     return i;

// }

int all(int *a,int s, int *o,int x){
    if(s==0) return 0;

    if(a[0]==x){
        o[0]=0;
    }

    int i= all(a+1,s-1,o,x);

    if(a[0]==x){
        int tmp=0;
        int p;
        for(int j=0;j<=i;j++){
            p=o[j];
            o[j]=tmp;
            tmp=p+1;
        }
        return i+1;
    }
    for(int j=0;j<i;j++) o[j]++;

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
