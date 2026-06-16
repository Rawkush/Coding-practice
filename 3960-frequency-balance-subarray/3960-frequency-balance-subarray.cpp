class Solution {
public:

    int getLength(vector<int>& nums) {
        int mx =0;   
        for(int i=0; i<nums.size(); i++) {
            unordered_map<int,int> mp;
            unordered_map<int,int> fmp; // freequcny vs number of elements
            for(int j=i; j<nums.size(); j++) {
                // this is a subarray
                int f = ++mp[nums[j]];
                fmp[f-1]--;
                if(fmp[f-1]<=0) {
                    // if there is only one element with this freequency and it was not udpated to w sop remove this from set
                    fmp.erase(f-1);
                }
                fmp[f]++;
                if(fmp.size()>2) continue;
                if(fmp.size() == 1 && mp.size()==1) mx = max(mx, j-i+1);
                else if(fmp.size()==1) continue;

                //now we know for sure we have size 2 fmp
                int first = -1;

                for (auto& [key, value] : fmp) {
                    // cout<<key<<" ";
                    if(first==-1) first = key;
                    else if(first == 2*key || 2*first == key) mx = max(mx, j-i+1);
                }
                // cout<< endl;
            }
        }    
        return mx;
    }
};