class Solution {
public:


/**
* space optimzated
*/


 bool canPartition(vector<int>& nums) {
        // since we need to partition the array the new arrau will be be arr1 + arr2 = arr
        int tsum=0;
        if(nums.size()<=1) return false;
        for(auto x: nums) tsum+=x;
        if(tsum%2!=0) return false;
        int  fsum= tsum/2;
        vector<bool> prev(tsum+1, false);
        vector<bool> curr(tsum+1, false);
        for(int i=0; i<nums.size(); i++) prev[0]=true;
        prev[nums[0]]= true;
        for(int i=1; i<nums.size(); i++){
            for(int j=1; j<=fsum; j++){
                bool notTake =  prev[j];
                bool take  = false;
                if(nums[i]<=j) take = prev[j-nums[i]];
                curr[j] = take || notTake;
            }
            prev= curr;
        }   
        return curr[fsum]; 
    }

   /**
   * iterative
   */

    // bool canPartition(vector<int>& nums) {
    //     // since we need to partition the array the new arrau will be be arr1 + arr2 = arr
    //     int tsum=0;
    //     if(nums.size()<=1) return false;
    //     for(auto x: nums) tsum+=x;
    //     if(tsum%2!=0) return false;
    //     int  fsum= tsum/2;
    //     vector<vector<bool>>dp(nums.size(), vector<bool>(tsum, false));
    //     for(int i=0; i<nums.size(); i++) dp[i][0]=true;
    //     dp[0][nums[0]]= true;
    //     for(int i=1; i<nums.size(); i++){
    //         for(int j=1; j<=fsum; j++){
    //             bool notTake =  dp[i-1][j];
    //             bool take  = false;
    //             if(nums[i]<=j) take = dp[i-1][j-nums[i]];
    //             dp[i][j] = take || notTake;
    //         }
    //     }   
    //     return dp[nums.size()-1][fsum]; 
    // }
/**
* Recursive
*/

    // bool helper(vector<int>&nums, int i, int target, unordered_map<int, unordered_map<int,int>>&mp ){
    //     if(target==0) return true;
    //     if(i<0 || target<0) return false;
    //     if(mp.count(i)>0 && mp[i].count(target)>0) return mp[i][target]==1;    
        
    //     return mp[i][target]= (helper(nums, i-1, target,mp) || helper(nums, i-1, target-nums[i],mp))? 1: 0;
    // }
    // bool canPartition(vector<int>& nums) {
    //     // since we need to partition the array the new arrau will be be arr1 + arr2 = arr
    //     int sum=0;
    //     for(auto x: nums) sum+=x;
    //     if(sum%2!=0) return false;

    //     // find whenther sum/2 exists in array or not, if does we can parition array
    //     unordered_map<int,unordered_map<int,int>>mp; 
    //     return sum%2==0? helper(nums, nums.size()-1, sum/2, mp) : false;
    // }
};