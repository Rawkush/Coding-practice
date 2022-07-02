#include<iostream>
using namespace std;


string addBinary(string a, string b) {
    unsigned short int c=0; //carry
    unsigned int blen=b.length();
    unsigned int alen=a.length();
    if(blen>alen){
        string tmp= a;
        a=b;
        b=tmp;
        unsigned int tmplen=alen;
        alen=blen;
        blen=tmplen;
    }
    string result="";
    for(int i=0; i<alen; i++){
       // cout<<result<<endl;
        if(i>=blen){
            unsigned short int f1 =0;
            if(a[alen-1-i]=='1')
                f1=1;
            if(f1^c){
                result="1"+result;
            }else{
                result="0"+result;
            }
             c=f1 & c;
        }else{
           unsigned short int f1 =0;
           unsigned short int f2 =0;

            if(a[alen-1-i]=='1')
                f1=1;
            if(b[blen-1-i]=='1')
                f2=1;
            if(f1^f2^c){
                result="1"+result;
            }else{
                result="0"+result;
            }
            c=(f1 & f2)|(f1&c)|(f2&c) ;
            cout<<f1<<" "<<f2<<" "<<c<<endl;
        }
    }
    if(c) result="1"+result;
    return result;
}

int main(){
    cout<<addBinary("110010","10111");
}