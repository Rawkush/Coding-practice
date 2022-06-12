#include<iostream>
using namespace std;

int main(){
  int arr []={1,2,3,4,5,6,7,8,9};
  int *p =arr;
  int *j=p+8;
  while(p!=j){
    cout<<*p<< " ";

    p=p+1;
  }
}