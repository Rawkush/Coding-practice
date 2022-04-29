#include<iostream>
using namespace std;
void swap(int &x, int &y){
    int t=x;
    x=y;
    y=t;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void rotate(int *arr, int d, int n)
{
    int i, j, k, temp;
    //starting point
    d= d%n;
        int g_c_d = gcd(d, n);

    for (i = 0; i < g_c_d; i++) {
        temp = arr[i];
        j = i;
        while (1) {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
int main(){
    int a[]={1,2,3,4}, size=4;
    rotate(a,2,size);
    for(int i=0; i<size ; i++){
        cout<<a[i]<<" ";
    }
}