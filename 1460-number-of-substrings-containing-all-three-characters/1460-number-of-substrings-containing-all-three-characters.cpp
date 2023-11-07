class Solution {
public:

  // substring with atmost 2 characters
  int helper(string s){
    int count =0;
    int l=0,r=0, n=s.size();
    int a[3] = {0,0,0};
    while(r<n){
      a[s[r]-'a']++;
      while(a[0]&&a[1]&&a[2]){
        a[s[l]-'a']--;
        l++;
      }
      count += r-l+1;
      r++;
    }
    return count;
  }
  int numberOfSubstrings(string s) {
    int n = s.size();
    long long c = (long)n*(n+1)/2;
    return c - helper(s);
  }
};