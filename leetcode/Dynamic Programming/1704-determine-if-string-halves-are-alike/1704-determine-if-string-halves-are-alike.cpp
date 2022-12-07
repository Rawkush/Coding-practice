class Solution {
public:
    bool halvesAreAlike(string s) {
      int count =0 ;
      string vowels = "aeiouAEIOU";
      for(int i=0; i<s.size()/2; i++){
        if(vowels.find(s[i])!=string::npos){
          count++;
        }
      }
      
      for(int i=s.size()/2; i<s.size(); i++){
        if(vowels.find(s[i])!=string::npos){
          count--;
        } 
      }
      return count ==0;
    }
};