class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> arr;
        for(int i=0; i<nums1.size(); i++) {
            arr.push_back({nums1[i], nums0[i]});
        }

        /**
        * 11100  11 11 11 11  for given input after sorting i will get this
        * this could have been 
        * 11 11 11 11 1100 which would result in biggest 
        * sor sort ka change hoga
        * most one but also with least 0
        */
        sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            
            /**
            * first one ones lenght 
            *
            */

            // if(totalLength1 != totalLength2) return totalLength1 < totalLength2;
            // if(a.first == b.first) return a.second < b.second;
            // return a.first > b.first;
            // if(a.second == b.second) return a.first < b.first;
            if(a.second == 0 && b.second == 0) return a.first >b.first;
            if(a.second == 0) return true;
            if(b.second == 0) return false;
            // if(a.second == b.second) a.first > b.second;

            // if(a.first == b.first) a.second > b.second;
            // // if(a.second == b.second) return a.first > b.first;


            // if(a.second != b.second) return a.second < b.second;
            // int t1 = a.first + a.second;
            // int t2 = b.first + b.second;
            // if total character are same then one with more 1's wins
            // if(t1==t2) 
            if(a.first >= b.first) {
                if(a.first == b.first) return a.second < b.second;
            }

            return a.first > b.first;
            // if t1 > t2 chars
            // if(t1 > t2) {
            // return a.second < b.second;
            // }
            // return t1 < t2;
        });

        string binary = "";
        for(int i=0; i<arr.size(); i++) {
            for(int j=0; j<arr[i].first; j++) {
                binary+="1";
            }
            for(int j=0; j<arr[i].second; j++) {
                binary+="0";
            }
        }
        // cout<<binary;
        long long ans = 0;
        long long n = binary.size();
        long long mod = 1e9 +7;
        for(long long i=0; i<n; i++) {
            ans = (ans<<1)%mod;
            if(binary[i]=='1') {
                ans = (ans+1)%mod;
            }
        }
        return ans;
    }
};