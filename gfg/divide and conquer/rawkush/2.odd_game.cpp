#include<iostream>
using namespace std;

long long oddGame(long long N) {
    // code here
            // code here
        if(N<=1)
            return 1;
        return 2*oddGame(N/2);
}


int main(){
    cout<<oddGame(5);

}
