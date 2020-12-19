#include<iostream>
using namespace std;

/*

https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I


*/



void conversion(string s, int n)
{
      int len=s.length();
        string tmp[n];
        int j=0;
    //bool increment=true;
        while(j<len){
        // from up to down
            for(int i=0; i<n;i++){
                if(j>=len)
                    break;
                tmp[i]=tmp[i]+s[j++];
            }
        // from down to up;
            for(int i=n-2; i>0;i--){
                if(j>=len)
                    break;
                tmp[i]=tmp[i]+s[j++];
            }

        }
        for(int i=1; i<n; i++)
            tmp[0]=tmp[0]+tmp[i];

        cout<<tmp[0];
}


int main()
{
    string s = "paypalishiring";
    int n=3;
    conversion(s, n);
    //cout<<str;
    return 0;
}
