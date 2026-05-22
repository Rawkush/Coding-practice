class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l=0, r= nums.size()-1;
        while(l<=r) {
            int m = (l+r)/2;
            if(nums[m]==t) return m;
            cout<<l<<" "<<r<<" "<<m<<endl;
            if(nums[l] < nums[m] && t<nums[m] && t >=nums[l]) {
                //sorted and keyt lies here
                r = m-1;
                continue;
            }
            if(nums[m] < nums[r] && t> nums[m] && t <=nums[r]) {
                l = m+1;
                continue;
            }
            // since above we saw the item is not in sorted part so it must be in 
            //non sorted path
            if(nums[l] > nums[m]) {
                r = m-1;
            }
            else l = m+1;
        }
        return  -1;
    }
};