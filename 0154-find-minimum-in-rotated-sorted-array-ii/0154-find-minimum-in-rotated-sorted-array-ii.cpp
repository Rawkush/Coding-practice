class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =0, r= nums.size()-1;
        int si =0;
        int ans = INT_MAX;
        while(r>l) {
            int mid = (l+r)/2;
            cout<< l<<" "<<r<<" "<<mid<<endl;
            ans = min(ans, nums[mid]);
            if(nums[l]  > nums[mid]) {
                r = mid;
                continue;
            }
            if(nums[mid] > nums[r]) {
                l = mid+1;
                continue;
            }
            if(nums[l]==nums[r] && nums[r]==nums[mid]) {
                l++;
                r--;
                continue;
            }
            if(nums[l]==nums[mid]) {
                l++;
                continue;
            }
            if(nums[r]==nums[mid]) {
                r--;
                continue;
            }
            
            //array is sorted
            ans = min(ans, nums[l]);
            break;
            
        }
        if(l==r && l<=nums.size()-1) {
            ans = min(ans, nums[l]);
        }
        return ans;
    }
};