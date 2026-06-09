class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        int mx = (1<<n); // max range
        vector<string> res;
        for(int i=0; i<mx; i++) {
            // 000
            string s ="";
            int cost = 0;
            bool valid = true;

            for(int j=0; j<n; j++) { // n bits
                /**
                * till 
                */
                if(i&(1<<j)) {
                    cost +=n-j-1;
                    if(cost > k || s[0]=='1') {
                        valid = false;
                        break;
                    }
                    s = "1" +s;
                }else s= "0" +s;
            }
            if(valid) {
                res.push_back(s);
            }
        }

        return res;
    }
};