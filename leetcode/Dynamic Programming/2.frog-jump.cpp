#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,bool>mem;

bool canCrossHelper( unordered_map<int, int> &stones, int idx, int jump, int destination){
  if(idx>= destination) return true;
  if(stones.find(idx)==stones.end()) return false;
  if(mem.find({idx, jump})!=mem.end()) return mem[{idx, jump}];
  bool result = false;
  if(jump>0){
    result = result || canCrossHelper(stones, idx+jump, jump, destination);
    result = result || canCrossHelper(stones, idx+jump-1, jump-1, destination);
  }
  result = result || canCrossHelper(stones, idx+jump+1, jump+1, destination);
  mem[{idx, jump}]=result;
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

//DP

bool canCross(vector<int> &stones){
  map<pair<int,int>,bool>mem;
  mem[{0,1}] = true;
  for(int i = 1; i <stones.size(); i++){
    for(int j = 0; j < i; j++){
      int jumpToReachDes = stones[i]- stones[j];
      if(jumpToReachDes <0 || jumpToReachDes > stones.size() || mem.find({j, jumpToReachDes})==mem.end()) continue;
      mem[{i,jumpToReachDes}]=true;
      if(jumpToReachDes - 1 >= 0) mem[{i,jumpToReachDes - 1}] = true;
      if(jumpToReachDes + 1 <= stones.size()) mem[{i, jumpToReachDes + 1}] = true;
      if(i==stones.size()-1) return true;
    }
  }
  return  false;
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