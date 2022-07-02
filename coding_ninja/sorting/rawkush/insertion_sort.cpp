#include<iostream>
using namespace std;

void insertionSort(int input[], int size)
{
    //Write your code here
    for (int i = 1; i <size; i++){
        int j=i-1;
        int x=input[i];
        while(j>=0 && input[j]>x){
            input[j+1]=input[j];
            j--;
        }
        input[j+1]=x;
    }
}
int main(){
    int a[]={5,4,3,2,1,0};
    insertionSort(a,6);
    for(int i=0; i <6 ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
