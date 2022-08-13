#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void subsetsHelper(vector<int> &nums, int index, vector<vector<int> > &result){
  if( index == nums.size() ) return;
  subsetsHelper(nums, index+1, result);
  int size = result.size();
  for(int i = 0; i < size; i++){
    vector<int> subset;
    subset.push_back(nums[index]);
    for(int j = 0; j < result[i].size(); j++){
      subset.push_back(result[i][j]);
    }
    result.push_back(subset);
  }
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> empty;
  result.push_back(empty);

  subsetsHelper(nums, 0, result);
  return result;
}

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  vector<vector<int>> tmp = subsets(v);
  cout<<"hello";
  cout<<tmp.size()<<endl;
  for(auto row: tmp){
    for(auto data: row){
      cout<<data<<" ";
    }
    cout<<endl;
  }
  return 0;
}