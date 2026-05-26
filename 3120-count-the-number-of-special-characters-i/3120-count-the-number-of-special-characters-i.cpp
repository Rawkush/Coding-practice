class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> s(26, 0);
        vector<int> c(26, 0);

        for(auto w:word) {
            int asci = (int)w;
            if(asci >=97) {
                s[w-'a']++;
            }else c[w-'A']++;
        }
        int count=0;
        for(int i=0; i<26; i++) {
            if(s[i]>=1 && c[i]>=1) count++;
        }
        return count;
    }
};