#include<iostream>
using namespace std;
/** symmetric means palindrome */
bool sym(int *arr, int left, int right){
    if(left<=right) return true;
    if(arr[left]!=arr[right]) false;
    return sym(arr, left+1, right-1);
}

int main(){
    int a[] = {0,1,2,2,1,0};
    cout<<sym(a,0,5);
}