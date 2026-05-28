class Solution {
public:
    /**
    * two cases max sum is directly in the array, i,e  startIndx < endIdx
    * or half part of roght and half of left arrya is is the max as it is ciruclar therfore endIdx < startIdx
    * for first we will use kadane for 2nd we wil tryu to find max  subarray with minimum sum in the mid array and minus it from total array sunm
    * which will give us left max and rogt max array sum
    */ 
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = INT_MIN; 
        int s = 0;
        int totalSum=0;
        for(int i=0; i<nums.size(); i++) {
            s+=nums[i];
            totalSum+=nums[i];
            mx = max(mx, s);
            if(s<=0) s=0;
        }
        cout<<mx<<endl;
        int minSum = INT_MAX;
        s=0;
        for(int i=0; i<nums.size(); i++) {
            s+=nums[i];
            cout<<s<<" ";
            minSum = min(minSum, s);
            if(s>=0) s=0;
        }
        if(totalSum!=minSum) mx = max(mx, totalSum-minSum);
        return mx;
    }
};