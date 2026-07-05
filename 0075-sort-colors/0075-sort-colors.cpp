class Solution {
public:
    void print(vector<int>& nums) {
        cout<<"nums; ";
        for(auto x: nums) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    void sortColors(vector<int>& nums) {
        int zeroIdx =0, oneIdx =0, twoIdx = nums.size()-1; 
        oneIdx = zeroIdx;
        while(oneIdx <= twoIdx && oneIdx<nums.size() && twoIdx>=0 && zeroIdx<nums.size() ) {
            // if(zeroIdx > oneIdx) oneIdx = zeroIdx;
            if(nums[oneIdx] == 0) {
                swap(nums[zeroIdx], nums[oneIdx]);
                zeroIdx++;
                oneIdx++;
            } else if(nums[oneIdx]==2) {
                swap(nums[oneIdx], nums[twoIdx]);
                twoIdx--;
            } else {
                oneIdx++;
            }
            cout<< zeroIdx<<" " <<oneIdx<< " "<<twoIdx<< " "<<endl;
            print(nums);
        }
        return;
    }
};