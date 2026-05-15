class Solution {
public:
    bool bs(vector<int>& nums, int l, int r, int t) {
        if(l==r) {
            return nums[l] ==t;
        }
        while(r>l) {
            int mid = (l+r)/2;
            if(nums[mid]==t) return true;
            if(nums[mid] > t) {
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int t) {
        int l =0, r= nums.size()-1;
        int si =  0;
        if(l==r) {
            return nums[l] ==t;
        }
        while(r>l) {
            int mid = (l+r)/2;
            if(nums[l] == t || nums[r]==t || nums[mid]==t) return true;
            cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[l] < nums[mid]) {
                if(nums[mid] > t && bs(nums, l, mid,t)) return true;
                l=mid+1; 
                continue;   
            }
            if(nums[mid] < nums[r]) {
                if(nums[mid] < t && bs(nums, mid, r,t)) return true;
                r =mid-1;
                continue;
            }
            /***/
            if(nums[l]==nums[r] && nums[mid]==nums[l]) {
                if(nums[l]==t) return true;
                l++;
                r--;
                continue;
            }
            if(nums[mid]==nums[r]) r--;
            if(nums[mid]==nums[l]) l++;
        }
        return false;
    }
};