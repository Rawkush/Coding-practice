#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool canCrossHelper( unordered_map<int, int> &stones, int idx, int jump, int destination){
  if(idx>= destination) return true;
  if(stones.find(idx)==stones.end()) return false;

  bool result = false;
  if(jump>0){
    result = result || canCrossHelper(stones, idx+jump, jump, destination);
    result = result || canCrossHelper(stones, idx+jump-1, jump-1, destination);
  }
  result = result || canCrossHelper(stones, idx+jump+1, jump+1, destination);
  return result;
}

bool canCross(vector<int> &stones){
  unordered_map<int, int> mp;
  for(int i = 0; i <stones.size(); i++){
    mp[stones[i]] = i;
  }
  int destination = stones[stones.size() - 1];
  return canCrossHelper(mp, 0, 1, destination);
}

int main(){
  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(3);
  v.push_back(6);
  v.push_back(7);
  cout<< canCross(v);
}