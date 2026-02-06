class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j=0;
        int n = nums.size();
        int mx = 0;
        while(i<n && j<n) {
            if(long(k)*nums[i]>=nums[j]) {
                mx = max(mx, j-i+1);
                j++;
            } else {
                i++;
            }
        }
        cout<<n<<" "<<mx;
        return n-mx;
    }
};