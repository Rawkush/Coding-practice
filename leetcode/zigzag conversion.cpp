#include<iostream>
using namespace std;




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
