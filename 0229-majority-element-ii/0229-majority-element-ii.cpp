class Solution {
public:

    int getF(vector<int>& nums, int num) {
        int f =0;
        for(auto x: nums) if(x==num) f++;
        return f;
    }

    vector<int> majorityElement(vector<int>& nums) {
        int c1 =0, c2=0;
        int e1 =0, e2 = 0;
        for(auto x: nums) {
            if(c1==0 && c2==0) {
                c1++;
                e1 = x;
            } else if(c1>0 && e1==x) {
                c1++;
            } else if(c2>0 && e2 ==x) {
                c2++;
            } else if( c1 >0 && c2 <=0) {
                e2 = x;
                c2++;
            } else if( c2 >0 && c1 <=0) {
                e1 = x;
                c1++;
            } else {
                c1--;
                c2--;
            }
        }

        vector<int> res;

        int f1 = getF(nums, e1);
        int f2 = getF(nums, e2);
        if(f1> nums.size()/3) res.push_back(e1);
        if(e1!=e2 && f2> nums.size()/3) res.push_back(e2);
        return res;
    }
};