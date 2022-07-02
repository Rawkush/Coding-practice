
#include<iostream>
using namespace std;


int  subseq(string inp, string out[]){
    if(inp.size()==0){
        out[0]="";
        return 1; //size of output array
    }
    //cant' tdo this in string
    //int size = subseq(inp+1, out);
    //instead we will use substring
    string remaining= inp.substr(1);
    int s = subseq(remaining, out);
    int i=0;
    for( i=0; i<s; i++){
        out[s+i]= out[i]+inp[0];
    }
    return s + i; // or 2*s
}
int main(){

    string a="abc";
    string* out= new string[1000];

    int count= subseq(a,out);
    for (int i=0;i<count;i++)
        cout<<out[i]<<endl;

}
