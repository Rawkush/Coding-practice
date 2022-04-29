#include<iostream>
using namespace std;


int binarySearch(int arr[], int l, int r, int x){
  if(r<l) return -1;
  int mid = l + (r - l) / 2;
  if (arr[mid] == x)
    return mid;
  if (arr[mid] > x)
    return binarySearch(arr, l, mid - 1, x);
  return binarySearch(arr, mid + 1, r, x);
}

int main(){

  int a[]={1,2,3,4,5,6,7,8,9};
  cout<<binarySearch(a,0,9, 3);


  return 0;
}