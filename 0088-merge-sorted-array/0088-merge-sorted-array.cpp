class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i=n-1, j=m-1;
        int rIdx = n+m - 1;
        while(i>=0 && j>=0) {
            if(nums1[i]>=nums2[j]) {
                nums1[rIdx] = nums1[i];
                i--;
                rIdx--;
            } else {
                nums1[rIdx] = nums2[j];
                j--;
                rIdx--;
            }
        }

        while(i>=0) {
            // cout<<nums1[i]<<" "<<endl;
            nums1[rIdx] = nums1[i];
            i--;
            rIdx--;
        }
        while(j>=0) {
            nums1[rIdx] = nums2[j];
            j--;
            rIdx--;
        }
        return;
    }
};