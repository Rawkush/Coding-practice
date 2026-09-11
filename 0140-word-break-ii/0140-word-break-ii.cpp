class Solution {
public:

    void helper( unordered_set<string>& mp, string s, int index, string sentence,vector<string> &res ) {
        if(index>=s.size()) {
            res.push_back(sentence);   
        };
        
        string tmpString = "";
        
        for(int i=index; i<s.size(); i++) {
            tmpString += s[i];
            
            if(mp.count(tmpString)>0) {
                if(sentence.size()>0) helper(mp, s, i+1, sentence + " " + tmpString, res);
                else helper(mp, s, i+1, tmpString, res);
            }
        }   
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp;
        vector<string> res;
        for(auto x:wordDict) {
            mp.insert(x);
        }
        helper(mp, s, 0, "",res);
        
        return res;
    }
};