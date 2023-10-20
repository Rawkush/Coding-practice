class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<int> uset;
    int mx= 0;
    int l=0,r=0;
  
    while(r<s.size()){
      if(uset.count(s[r])==0){
        uset.insert(s[r]);
        mx = max(mx, r-l+1);
      }else{
        // found duplicate somewhere
        // very similar to monotomnic stack, bt insetead of increasing or decerasing
        // we have duplicate
        while(uset.count(s[r])){
          uset.erase(s[l]);
          l++;
        }
        uset.insert(s[r]);
      }
      r++;
    }
    return mx;
  }
};