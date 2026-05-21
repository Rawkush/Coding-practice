class Solution {
public:
    string compressedString(string word) {
        string s="";
        int f=1;
        for(int i=0; i<word.size(); i++) {
        //    cout<<s<<endl; 
           if(i <word.size()-1 && word[i]!=word[i+1]) {
              s +=to_string(f) + word[i];
              f = 1;
              continue;
           }
           if(i==word.size()-1) {
              s+=to_string(f) + word[i];
              continue;
           }
           if(f==9) {
             s+=to_string(f) + word[i];
             f=1;
             continue;
           }
           f++;
        }
        return s;    
    }
};