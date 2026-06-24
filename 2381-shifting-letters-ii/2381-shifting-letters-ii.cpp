class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size()+1, 0);
        for(auto x:shifts) {
            int l =x[0];
            int r = x[1];
            int ss = x[2] == 0? -1 : 1; // shift forward or ereverse
            diff[l] +=ss;
            diff[r+1] -=ss;
        }

        //now my diff arrya is built now make a prefix arr
        for(int i=1; i<diff.size(); i++) {
            diff[i] +=diff[i-1];
        }

        //now i have prefix sum array that tells each item to rotate how much
        for(int i=0; i<diff.size()-1; i++) {
            // cout<<diff[i]<<" ";
            int ascii = s[i] - 'a';
            if(diff[i] < 0 && (ascii+diff[i]) < 0) {
                int d = abs(ascii+diff[i])%26;
                s[i] = 'a' + (26-d)%26;
            } else {
                int d = (ascii + diff[i])%26;
                s[i] = 'a' + d;
            }
        }
        return s;
    }
};