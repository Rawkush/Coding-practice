#include<iostream>
using namespace std;

void insertionSort(int *input, int size)
{
    //Write your code here
    for (int i = 0; i <size-1; i++){
        for(int j = i+1; j >0 ;j--){
            if(input[j]<input[i]){
                int temp= input[j];
                input[j]=input[i];
                input[i]=temp;
            }
        }
    }
}
int main(){

    int x=10,  y=12;
    int t=x;
        x=y;
        y=t;

    int a[]={5,4,3,2,1,0};
    insertionSort(a,6);
    for(int i=0; i <6 ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
