class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        s+=chars[0];
        int i=0;
        for(int j=0; j<chars.size(); j++) {
            if(i==j) continue;
            if(chars[i] == chars[j]) {
                if(j==chars.size()-1) s+=to_string(j-i+1);
                continue;
            }
            else {
                if(i+1 ==j) {
                    //as i is already part i=of the string on j needed
                    s+=chars[j];
                    i=j;
                    continue;
                }
                s += to_string(j-i);
                s+=chars[j];
                i=j;
            }
        }
        for(int i=0; i<s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};