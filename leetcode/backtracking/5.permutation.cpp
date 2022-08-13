#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<int>&permutation, int num){
  for(int i = 0; i < permutation.size(); i++){
    if(permutation[i]==num) return false;
  }
  return true;
}

void permuteHelper(vector<int>& nums, vector<int> &permutation, vector<vector<int>>&result){
  if(permutation.size()== nums.size()){
    result.push_back(permutation);
    return;
  }
  for(int i=0; i<nums.size(); i++){
    if(isSafe(permutation, nums[i])){
      permutation.push_back(nums[i]);
      permuteHelper(nums, permutation, result);
      permutation.pop_back();
    }
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> permutation;
  permuteHelper(nums, permutation, result);
  return result;
}

int main(){

  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  vector<vector<int>> p = permute(nums);
  for(auto i: p){
    for(auto j: i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}