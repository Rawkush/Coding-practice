class Solution {
public:
void helper(vector<int> &nums, stack<int> &st, vector<int>&res){
   for(int i=nums.size()-1; i>=0; i--){
     if(st.empty()){
       st.push(nums[i]);
     }
    else{
      if(st.top() <= nums[i]){
        while(!st.empty() && st.top() <= nums[i] )st.pop();
        if(res[i]==-1 && !st.empty()) res[i] = st.top();
        st.push(nums[i]);
      }else 
      if(st.top()>nums[i]){
        if(res[i]==-1) res[i] = st.top();
        st.push(nums[i]);
      }
    }
   }  
}
  vector<int> nextGreaterElements(vector<int>& nums) {
   vector<int> res(nums.size(), -1);
   stack<int> st;
   helper(nums, st, res);
   helper(nums, st, res);
   return res;
  }
};