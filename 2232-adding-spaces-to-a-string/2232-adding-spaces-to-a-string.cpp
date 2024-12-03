class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        int st=0;
        for(int i=0; i<s.size(); i++){
            if(st<spaces.size() && i==spaces[st]){
                res+=" ";
                st++;
            }
            res+=s[i];
        }

        return res;
    }
};