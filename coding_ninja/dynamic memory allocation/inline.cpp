#include<iostream>
using namespace std;

/*
    inline fumcton calls are replaced with acutal code of the fuctin
    during compiling so it makes code fast while execution

*/

// this is fast
inline int max(int a, int b){
    return (a>b)? a:b;
}

//this is slow
int min(int a, int b){
    return (a<b)? a:b;
}


int main(){

    cout<<max(5,8)<<endl;
    cout<<min(6,9);

}
