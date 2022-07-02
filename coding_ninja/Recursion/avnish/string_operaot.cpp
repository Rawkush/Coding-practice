#include<iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


bool isDigit(char c){
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'|c=='6'||c=='7'||c=='8'||c=='9')
        return true;
    return false;
}


int whichDigit(char c){

    if(c=='0')
        return 0;

    if(c=='1')
        return 1;

    if(c=='2')
        return 2;

    if(c=='3')
        return 3;

    if(c=='4')
        return 4;

    if(c=='5')
        return 5;

    if(c=='6')
        return 6;


    if(c=='7')
        return 7;

    if(c=='8')
        return 8;

    if(c=='9')
        return 9;

}

double getAns(double a, int b, char c){

    if(c=='*')
        return a*b;
    if(c=='+')
        return a+b;
    if(c=='/')
        return a/b;
    if(c=='-')
        return a-b;


}

int main(){
    string a="12345*+-+";
    queue <int> s;
    queue<int> q;


    for(int i=0; a[i]!='\0';i++){
            if(isDigit(a.at(i))){
                q.push(whichDigit(a.at(i)));
            }else
                s.push(a.at(i));
    }


    double ans=q.front();
    q.pop();
    while (!s.empty()) {
        char c=s.front();
        s.pop();
        ans=getAns(ans,q.front(), c);
        q.pop();
    }
    cout<<ans;
}
