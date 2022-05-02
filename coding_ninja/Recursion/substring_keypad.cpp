#include<iostream>
using namespace std;

int substring_keypad(int num, string out[]){
    string str="";
    if(num<=1){
        out[0]=str;
        return 1;
    }
    int remainder = num%10;
    num /=10;
    switch(remainder){
        case 2: str="abc";
            break;
        case 3: str="def";
            break;
        case 4: str = "ghi";
            break;
        case 5: str= "jkl";
            break;
        case 6: str = "mno";
            break;
        case 7 : str="pqrs";
            break;
        case 8: str="tuvw";
            break;
        case 9: str="xyz";
            break;
        default:
            str="";
            break;
    }
    int size=substring_keypad(num, out);
    for(int j=0; j< str.size(); j++){
        for(int i=0; i<size;i++){
            out[size+i]=out[i] +str[j];
        }
        size=size+j;
    }
    return size;
}

int main(){
    string a="abc";
    string* out= new string[1000];

    int count= substring_keypad(2,out);
    for (int i=0;i<count;i++)
        cout<<out[i]<<endl;

    return 0;
}
