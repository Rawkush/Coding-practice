class Solution {
public:

/**
* without set/map using swap;
*/
/**
* idea is to keep first element same by swapping, now recursion will make sure
* that all combinattion of it are calculated
*/

  void helper(vector<int>&nums, int idx, vector<vector<int>> &res){
    if(idx>= nums.size()){
      res.push_back(nums);
      return;
    }

    //swap all element and bring them to idx
    for(int i=idx; i<nums.size(); i++){
      swap(nums[idx], nums[i]);
      helper(nums, idx+1, res);
      swap(nums[idx], nums[i]); 
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      helper(nums, 0, res);
      return res;
  }




/**
*  using map
*/
    // void helper(vector<int>& nums, unordered_set<int>& uset, vector<int>& per,
    //             vector<vector<int>>& res) {
    //     if (per.size() == nums.size()) {
    //         res.push_back(per);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (uset.find(nums[i]) != uset.end())
    //             continue; // do not include element already added
    //         per.push_back(nums[i]);
    //         uset.insert(nums[i]);
    //         helper(nums, uset, per, res);
    //         per.pop_back();
    //         uset.erase(nums[i]);
    //     }
    // }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     unordered_set<int> uset;
    //     vector<int> per;
    //     vector<vector<int>> res;
    //     helper(nums, uset, per, res);
    //     return res;
    // }
};