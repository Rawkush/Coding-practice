#include<iostream>
using namespace std;


int binarySearch(int *input, int n, int val)
{
    //Write your code here
 	int left =0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;

        if(input[mid]==val)
            return mid;

        if(val>input[mid]){
            left=mid+1;
        }

        if(val<input[mid]){
            right=mid-1;
        }
    }
    return -1;
}

int main(){

    int array[]={1,23,4,5,6,7,8,9,10,11,12,13};
    int find=10;

    cout<<binarySearch(array,13,find);
    return 0;
}