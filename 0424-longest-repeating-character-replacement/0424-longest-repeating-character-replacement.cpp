class Solution {
public:

/**
The problem says that we can make at most k changes to the string (any character can be replaced with any other character). So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. The answer to this is

length of the entire string - number of times of the maximum occurring character in the string

Given this, we can apply the at most k changes constraint and maintain a sliding window such that

(length of substring - number of times of the maximum occurring character in the substring) <= k
*/


  int getMax(vector<int> &fcount){
    int mx = INT_MIN;
    for(auto x:fcount){
      mx = max(mx,x);
    }
    return mx;
  }

  int characterReplacement(string s, int k) {
    int l=0, r=0;
    // unordered_map<char, int> mp;
    vector<int> fcount(26, 0);
    int mf=0; //maxcharacter freequency;
    int result =0;
    // length -max-recurring charcter <=k
    while(r<s.size()){
      int substrlen = r-l+1;
      int cf = ++fcount[s[r]-'A']; //current char freequency
      if(mf<cf){
        mf = cf; 
      }
      int maxStep = substrlen - mf;    
      while(k< maxStep){
        fcount[s[l]-'A']--;
        mf = getMax(fcount); // since arr size is 26, so TC is O(1)
        substrlen--;
        maxStep = substrlen - mf;    
        l++;
      }
      result = max(result, substrlen); // we have to return length of max substr
      r++;
    }
    return result;
  }
};