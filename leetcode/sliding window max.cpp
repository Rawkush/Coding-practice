#include<bits/stdc++.h>
#include<iostream>>
#include<string>
using namespace std;

/*

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]

Example 4:

Input: nums = [9,11], k = 2
Output: [11]

Example 5:

Input: nums = [4,-2], k = 2
Output: [4]


*/

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



