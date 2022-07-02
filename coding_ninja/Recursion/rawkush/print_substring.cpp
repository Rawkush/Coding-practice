#include<iostream>
using namespace std;

void print_subs(string inp, string output){
    if(inp.length()==0){
        cout<<output<<endl;;
        return;
    }
    //not include inp[0]
    print_subs(inp.substr(1), output);
    //include inp[0] in output
    print_subs(inp.substr(1), output+inp[0]);
}

int main(){
    string inp="ab";
    string output="";
    print_subs(inp,output );
    return 0;
}
