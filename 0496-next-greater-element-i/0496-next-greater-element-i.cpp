#define log(x) cout<<#x<<" "<<x<<endl;
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    stack<int> st;
    unordered_map<int, int> umap;
    for(int i=nums2.size()-1; i>=0; i--){
      if(st.empty()){
        st.push(nums2[i]);
        umap[nums2[i]] = -1;
      }else{
        if(st.top() > nums2[i]){
          umap[nums2[i]] = st.top();
          st.push(nums2[i]);
        }else{
          while(!st.empty() && st.top() < nums2[i]) st.pop();
          umap[nums2[i]] = st.empty() ? -1 : st.top();
          st.push(nums2[i]);
        }
      }
    }

    for(int i=0; i<nums1.size(); i++){
      res.push_back(umap[nums1[i]]);
    }

    return res;
  }
};