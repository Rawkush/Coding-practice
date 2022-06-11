// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<stack>
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    stack<char> s;
    bool ispar(string x)
    {

        // Your code here
        for(int i=0; i < x.size();i++){

            switch(x[i]){
                case '{': s.push('{'); break;
                case '(': s.push('('); break;
                case '[': s.push('['); break;
                case '}':
                if(s.empty()) return false;
                    if(s.top()=='{'){
                        s.pop();
                        break;
                    }else{
                        return false;
                    }
                    break;
                case ')':
                if(s.empty()) return false;

                if(s.top()=='('){
                    s.pop();
                    break;
                }else{
                    return false;
                }
                break;
                case ']':
                if(s.empty()) return false;
                if(s.top()=='['){
                    s.pop();
                    break;
                }else{
                    return false;
                }
                break;
                default: break;
            }


        }

        return s.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends