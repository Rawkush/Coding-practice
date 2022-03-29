#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        cout<<"Found "<< left<<" "<<right<<endl;
        if(nums[mid]==target){
            return mid;
        }else
        if(nums[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return left;
}

int main(){
    vector<int> nums{1,3,5,6};
    int target =7;
    cout<< searchInsert(nums, target);
    return 0;
}