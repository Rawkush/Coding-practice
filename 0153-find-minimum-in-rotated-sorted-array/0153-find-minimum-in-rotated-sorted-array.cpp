class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =0, r= nums.size()-1;
        int si =0;
        while(r>l) {
            int mid = (l+r)/2;
            cout<< l<<" "<<r<<" "<<mid<<endl;
            if(nums[l]  > nums[mid]) {
                r = mid;
            }else if(nums[mid] > nums[r]) {
                l =mid+1;
            }else {
                //whole array is sorted 
                break;
            }
        }
        return nums[l];
    }
};