class Solution {
public:
    void print(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    vector<int> maxValue(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        /** these will store index */
        vector<int> max_on_left(nums.size());
        vector<int> min_on_right(nums.size());
        max_on_left[0] = nums[0];
        min_on_right[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++) {
            max_on_left[i] = max(max_on_left[i-1],nums[i]);
        }
        for(int i = nums.size() - 2; i >= 0; i--) {
            min_on_right[i] = min(min_on_right[i+1],nums[i]);
        }
        // print(max_on_left);
        // print(min_on_right);
        int max_so_far = max_on_left[nums.size()-1];
        int min_so_far = min_on_right[nums.size()-1];

        for(int i=nums.size()-1; i>=0; i--) {
            int n=nums[i];
            if(n<max_so_far && n>min_so_far ) {
                res[i] = max_so_far;
            } else {
                int mx = max_on_left[i];
                if(mx>min_so_far) {
                    res[i] = max_so_far;
                    min_so_far = min_on_right[i];
                }else {
                    min_so_far = min_on_right[i];
                    max_so_far = max_on_left[i];
                    res[i] = max_so_far;
                }
              
            }
        }
        return res;
    }
};