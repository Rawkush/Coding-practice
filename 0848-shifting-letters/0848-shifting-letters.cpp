class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int previousShift =0 ;
        for(int i=shifts.size()-1; i>=0; i--) {
            // cout<<previousShift<<endl;
            int shift = (previousShift+shifts[i])%26; 
            int ascii = s[i] - 'a';
            int asciiAfterShift = (ascii + shift) %26;
            s[i] = asciiAfterShift + 'a';
            previousShift=( previousShift + shifts[i])%26;
        }
        return s;
    }
};