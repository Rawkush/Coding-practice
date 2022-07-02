#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for (int i =0;i<nums.size(); i++){
        if(s.count(nums[i])){
            return true;
        }
        else s.insert(nums[i]);
    }
    return false;
}

int main(){
    vector<int> array{1,2,3,1};
    cout<<containsDuplicate(array);
    return 0;
}