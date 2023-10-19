class Solution {
public:
/**
All subarray sizes till size k - all subarray sizes till size k-1 =  all subarray of exact size k

Well, suppose you have a room with a bunch of children in it. It turns out that there are 12 children who are five years old or under, and 8 children who are four years old or under.

Now presumably you agree that each one of the "children four years old or under" is also one of the "children five years old or under," right?

So suppose we take the 12 children five years old or younger, and remove from them the 8 children four years old or younger. Of course, 12 - 8 = 4 children remain.

*/
  // calculate all subset till valid
  int helper(vector<int>& nums, int k){
    unordered_map<int, int> mp; // value , count
    int i=0;
    int count =0;
    int st = 0;
    while(i<nums.size()){
      mp[nums[i]]++;
      while(mp.size()>k){
        mp[nums[st]]--;
        if(mp[nums[st]]==0) mp.erase(nums[st]);
        st++;
      }
      count += i-st+1;
      i++;
    }
    return count;
  }
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return (helper(nums, k)- helper(nums, k-1));
  }
};