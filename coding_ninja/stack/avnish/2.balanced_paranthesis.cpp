#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string expression)
{
    // Write your code here
    stack <char> st;
    for(int i=0; i<expression.size(); i++)
    {
        if(expression[i]=='('||expression[i]=='{' || expression[i]=='[')
        {
            st.push(expression[i]);
        }
        else
        {

            switch(expression[i])
            {
            case '}':
                if(st.empty()){
                    return false;
                }
                if(st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
              if(st.empty()){
                    return false;
                }
                if(st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ')':
              if(st.empty()){
                    return false;
                }
                if(st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }
    }

    return st.empty();
}

int main()
{
    stack<char> s;
    // s.push(1);
    // cout<<s.empty();
   if(isBalanced("()())")){
       cout<<"TRUE";
   }else cout<<"FALSE";
    return 0;
}
