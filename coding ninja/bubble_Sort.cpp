#include<iostream>
using namespace std;

void bubbleSort(int *input, int size)
{
    //Write your code here
    for (int j = 0; j < size; j++)
    for(int i = 0; i < size-1; i++){
        if(input[i] >input[i+1]){
            int t=input[i];
            input[i]=input[i+1];
            input[i+1]=t;
        }
    }
    for(int i = 0;i<size;i++){
        cout<<input[i]<< endl;
    }

}

int main(){
    int a[]={5,4,3,2,1,0};
    bubbleSort(a,6);
    return 0;
}