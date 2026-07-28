class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> mp(26, 0);
        for(auto x:s) {
            mp[x-'a']++;
        }

        int i = 0;
        int j = s.size()-1;
        for(int k=0; k<26; k++) {
            while(mp[k]>0) {
                char c = 'a'+k;
                if(mp[k]==1) {
                   s[s.size()/2] = c;
                   break; 
                }
                s[i++] = c;
                s[j--] = c;
                mp[k] -= 2;
            }
        }
        return s;
    }
};