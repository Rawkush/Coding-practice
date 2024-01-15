class Solution {
public:
  unordered_map<char, string> mp;

  void helper(string digits, int idx, string rep, vector<string> &res){
    if(idx>= digits.size()){
      if(rep=="") return;
      res.push_back(rep);
      return;
    }

    char key = digits[idx];
    string possibleValues = mp[key];
    for(int i=0; i<possibleValues.size(); i++){
      helper(digits, idx+1, rep+possibleValues[i], res);
    }
  }

  vector<string> letterCombinations(string digits) {
    mp.insert({'2', "abc"});
    mp.insert({'3', "def"});
    mp.insert({'4', "ghi"});
    mp.insert({'5', "jkl"});
    mp.insert({'6', "mno"});
    mp.insert({'7', "pqrs"});
    mp.insert({'8', "tuv"});
    mp.insert({'9', "wxyz"});
    vector<string> res;
    helper(digits, 0, "", res);
    return res;
  }
};