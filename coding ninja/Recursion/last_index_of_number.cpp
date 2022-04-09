

 #include<iostream>
using namespace std;

int last_index(int *a,int n, int s){
   if(n<=0)
      return -1;
    if(a[n-1]==s) return n-1;
   return last_index(a,n-1,s);
 }


 int main(){

    int a[]={5,5,6,5,6};
    int size=5;
    cout<<last_index(a,size-1,5);

 }
