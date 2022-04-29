#include<bits/stdc++.h>
#include<iostream>>
#include<string>
using namespace std;

void maxSlidingWindow(int* nums, int k) {
    int size=6;
    deque <int> dq;
    int i=0;
    dq.push_front(0);
    for(i=1;i<k;i++){
          if(nums[dq.front()]<=nums[i]){
            dq.pop_front();
            dq.push_back(i);
        }

    }

    cout<<"size "<<dq.size()<<endl;

    for(i=k-1;i<size;++i){

        if(dq.front()<=i-k){
            dq.pop_front();
        }

        while(!(dq.empty())&&nums[dq.front()]<=nums[i])
            dq.pop_front();

        dq.push_back(i);
        cout<<nums[dq.front()]<<" ";
    }


}

int main(){
    //int a[]={1,3,1,2,0,5};
    //int k=3;
    //maxSlidingWindow(a,k);
    string s;
    getline(cin,s);
    cout<<s<<endl<<s.length()<<endl;
    string max="";
    string tmp="";
    int count =0;
    for(int i=0; i< s.length(); i++){
        if(s[i]<='z'&& s[i]>='a'){
            tmp=tmp+s[i];
            count++;
        }
        else{
            if(count>max.length())
                max=tmp;
            tmp="";
            count=0;
        }
    }
        cout<<max;
}
