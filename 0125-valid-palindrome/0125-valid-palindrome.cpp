class Solution {
public:
  void lower(string& s){
    for(int i=0;i<s.length();i++){
      if(s[i]>='A'&&s[i]<='Z')
        s[i]=s[i]-'A'+'a';
    }
  }

  bool isAlphaNumeric(char s){
    if(s>='a'&&s<='z'||s>='0'&&s<='9'){
      return true;
    }
    return false;
  }

  bool isPalindromeHelper(string &s, int si, int li){
    if(si>=li) return true;
    if(isAlphaNumeric(s[si]) && isAlphaNumeric(s[li])){
      if(s[si]==s[li]){
        return isPalindromeHelper(s, si+1, li-1);
      }
      else return false;
    }
    if(!isAlphaNumeric(s[si])){
      return isPalindromeHelper(s, si+1, li);
    }
    if(!isAlphaNumeric(s[li])){
      return isPalindromeHelper(s, si, li-1);
    }
    return false;
  }

  bool isPalindrome(string s) {
    lower(s);
    return isPalindromeHelper(s, 0, s.size()-1);
  }
};