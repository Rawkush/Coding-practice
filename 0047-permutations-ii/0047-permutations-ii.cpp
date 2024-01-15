class Solution {
public:
/************* TWO METHODS********/
//  1 => USING SWAPS
  void helper(vector<int>& nums, int idx, vector<vector<int> >& res) {
    if (idx >= nums.size()) { 
      res.push_back(nums); return; 
    }
    unordered_set<int> st;
    for (int i = idx; i < nums.size(); i++) {
      if(st.find(nums[i])!=st.end()) continue;
      st.insert(nums[i]);
      swap(nums[idx], nums[i]);
      helper(nums, idx+1, res);
      swap(nums[idx], nums[i]);
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > result;
    helper(nums, 0, result);
    return result;
  }

  /**
  * order of same number does not matter so used map with number freequency, so that it's order won't be considered when generating the permutations
  */
  // void helper(unordered_map<int,int>&umap, vector<int> &sub, vector<vector<int>>&res, int n ){
  //   if(sub.size()==n){
  //     res.push_back(sub);
  //     return;
  //   }

  //   for(auto it = umap.begin(); it!=umap.end(); it++){
  //     if(!it->second) continue;
  //     sub.push_back(it->first);
  //     it->second--;
  //     helper(umap, sub, res, n);
  //     sub.pop_back();
  //     it->second++;
  //   }
  // }
  // vector<vector<int>> permuteUnique(vector<int>& nums) {
  //   unordered_map<int,int> umap;
  //   vector<vector<int>> res;
  //   vector<int> sub;
  //   for(auto x:nums) umap[x]++;
  //   // unordered_map<int,int>::iterator it;
  //   // it = umap.begin();
  //   helper(umap, sub, res, nums.size());
  //   return res;
  // }
};