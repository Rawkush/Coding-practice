#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums{0,1,2,2,3,0,4,2};
    int val=2;
    int j=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==val){
            continue;
        }
        nums[j++]=nums[i];
    }

    return 0;
}