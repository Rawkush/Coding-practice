class Solution {
public:

  bool checkIfSubset(unordered_map<char,int>&mp1, unordered_map<char, int> &mp2){
    for(auto it:mp2){
      if(mp1[it.first]<it.second) return false;
    }
    return true;
  }

  string minWindow(string s, string t) {
    if(s.size()<t.size()) return "" ; 
    int n = s.size();
    int k = t.size(); //window size
    int l=0,r=0;
    string res = "";
    unordered_map<char,int> subf;
    for(int i=0;i<t.size(); i++){
      subf[t[i]]++;
    }

    unordered_map<char,int> wf; //wordFreequency for current
    for(r=0; r<k; r++){
      wf[s[r]]++;
    }

    //start sliding window
    int start=0, end=0;
    int minLen = INT_MAX;

    if(checkIfSubset(wf, subf)){
      minLen = r-l;
      start=0;
    }

    for(r=k; r<n; r++){
      wf[s[r]]++;
      while(checkIfSubset(wf, subf) && r-l+1 >=k){
        if(minLen>r-l+1){
          minLen = r-l+1;
          start = l;
        }
        wf[s[l]]--;
        if(wf[s[l]]==0) wf.erase(s[l]);
        l++;
      }
    }
    if(minLen==INT_MAX) return "";
    return s.substr(start, minLen);
  }
};