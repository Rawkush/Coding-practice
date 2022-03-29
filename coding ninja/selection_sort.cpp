#include<iostream>
#include<vector>
using namespace std;

int main(){
    int array [] ={8,6,1,2,3,5,6,7,9,0};
    for(int i=0; i<10;i++){
        int min = i;
        for(int j=i+1; j<10;j ++){
            if(array[j] < array[min]){
                min=j;
            }
        }
        int t=array[min];
        array[min]=array[i];
        array[i]=t;
    }
    for(int i=0;i<10;i++){
        cout << array[i] << endl;
    }
    return 0;
}