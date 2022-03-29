#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Partition(int *a, int l, int r){
    int pivot= a[l];
    int c=0;
    for(int i=l; i<=r; i++){
        if(a[i]<pivot)
            c++;
    }

    swap(a[l],a[l+c]);
    int i=l, j=r;
    while(i<j){
        while(a[i]<pivot){
            i++;
        }

        while(a[j]>pivot){
            j--;
        }
        if(a[i]!=pivot)
            swap(a[i],a[j]);

    }
    return l+c;
}


void quicksort(int *a, int l, int r){
    if(l>=r)
        return;
    int c= Partition(a,l,r);
    quicksort(a, l ,c-1);
    quicksort(a,c+1,r);
}

int main(){

    int a[]={1,9,7,2,3,4,17};
    quicksort(a,0,6);
    for(int i=0; i<7;i++)
        cout<<a[i]<<" ";


}
