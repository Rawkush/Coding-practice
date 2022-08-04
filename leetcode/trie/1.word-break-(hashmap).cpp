#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

bool wordBreakHelper(string s, unordered_map<string, int>& map, unordered_map<string,bool>& mem) {
  if(map.find(s) != map.end()) return true;
  if(mem.find(s) != mem.end()) return mem[s];
  string tmp="";
  for(int i = 0; i < s.size(); i++) {
    tmp=tmp+s[i];
    if(map.find(tmp) != map.end()){
      string remainingString = s.substr(i+1);
      bool result=wordBreakHelper(remainingString, map, mem);
      if(result){
        mem[s]=true;
        return true;
      }
    }
  }
  mem[s]=false;
  return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_map<string, int> map;
  for(auto word: wordDict){
    map[word]++;
  }
  unordered_map<string, bool> mem;
  return wordBreakHelper(s, map, mem);
}

int main(){
  vector<string> wordDict;
  wordDict.push_back("leet");
  wordDict.push_back("code");
  cout<<wordBreak("leetcode", wordDict);
}