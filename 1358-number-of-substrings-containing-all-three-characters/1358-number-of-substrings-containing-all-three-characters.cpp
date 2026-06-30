class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3, 0);
        int count =0;
        int i = 0;
        for(int j=0; j<s.size(); j++) {
            mp[s[j] -'a']++;
            while(mp[0] && mp[1] && mp[2]) {
                count+=s.size()-j;
                mp[s[i]-'a']--;
                i++;
            }
        }
        return count;
    }
};