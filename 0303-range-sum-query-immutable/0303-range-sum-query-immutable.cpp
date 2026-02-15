class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int sum =0;
        for(auto x: nums) {
            sum+=x;
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixSum[right];
        int sum_from_0_left = prefixSum[left-1]; // since range should include left as well so left-1
        int sum_from_0_right = prefixSum[right];
        return sum_from_0_right - sum_from_0_left;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */