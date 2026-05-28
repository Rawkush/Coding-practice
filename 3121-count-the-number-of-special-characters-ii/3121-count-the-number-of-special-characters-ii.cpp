class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        vector<int> mp(26, -1);
        for(int i=0; i<word.size(); i++) {
            char c = word[i];
            int ascii = (int)c;
            if(ascii < 97 && mp[c-'A']==-1) {
                mp[c-'A'] = i;
            }
        }

        // -1 is not processed, 1 it is special char, 0 it is not 
        vector<int> sp(26, -1);
        
        for(int i=0; i<word.size(); i++) {
            char c = word[i];
            int ascii = (int) c;
            if(ascii < 97 || mp[c-'a'] == -1) continue;
            // if it exists then
            if(mp[c-'a'] > i) {
                if(sp[c-'a']==-1) {
                    sp[c-'a'] = 1;
                    count++;
                }                
            } else {
               if(sp[c-'a']==1) {
                    count--;
                    sp[c-'a'] = 0;
               } 
            }
        }
        return count;
    }
};