class Solution {
public:

bool areIdentical(vector<int>& a, vector<int>&  b){
  for(int i=0; i<26; i++){
    // cout<<a[i]<<" "<<b[i]<<endl;
    if(a[i]!=b[i]) return false;
  }
  return true;
}


bool checkInclusion(string s1, string s2) {
  if(s1.size()>s2.size()) return false;

  vector<int> s1Map(26,0);
  vector<int> s2Map(26,0);
  for(auto ch: s1){
    s1Map[ch-'a']++;
  }
  //create a window of S1.size
   for(int i=0; i<s1.size(); i++){
    s2Map[s2[i]-'a']++;
  }
  int first =0;
  if(areIdentical(s1Map, s2Map)) return true;
  for(int i=s1.size(); i<s2.size(); i++){
    s2Map[s2[first++]-'a']--;
    s2Map[s2[i]-'a']++;
    if(areIdentical(s1Map, s2Map)) return true;
  }
  return false;
}

};