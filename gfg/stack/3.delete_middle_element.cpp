// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#include <cmath>

class Solution
{
    public:


    void deleteS(stack<int>&s, int mid){
        if(mid==0){
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        deleteS(s, mid-1);
        s.push(top);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        deleteS(s, ceil((sizeOfStack)/2));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;

    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;

        stack<int> myStack;

        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends