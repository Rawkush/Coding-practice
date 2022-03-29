#include<iostream>
using namespace std;

int  subseq(string inp, string out[]){
    if(inp.size()==0){
        out[0]="";
        return 1;
    }

    /*
        cant doo this in string
        int s= subseq(inp+1,out);
    */

    string remaining= inp.substr(1);
    int s= subseq(remaining,out);

    for(int i=0; i< s; i++){
        out[i+s]=inp[0] + out[i];

    }

    return 2*s;

}

int main(){

    string a="abc";
    string* out= new string[1000];

    int count= subseq(a,out);
    for (int i=0;i<count;i++)
        cout<<out[i]<<endl;

}
