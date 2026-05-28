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

        for(int i=word.size()-1; i>=0; i--) {
            char c = word[i];
            int ascii = (int) c;
            if(ascii<97 || mp[c-'a']==-1) continue;
            if(i > mp[c-'a']) {
                mp[c-'a'] =-1;
            } else {
                count++;
                mp[c-'a'] =-1;
            }
        }

        return count;
    }
};
