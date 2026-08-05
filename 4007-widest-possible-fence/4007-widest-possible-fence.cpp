class Solution {
public:

    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq;
        unordered_map<int, int> sumCount;
        int c = 1;
        for(auto x:planks){
            freq[x]++;
            sumCount[x]++;
            c = max(c, sumCount[x]);
            // cout<<x<<":"<<sumCount[x]<<endl;
        }
        int n = freq.size();

        vector<int> heights;
        for(auto x:freq) heights.push_back(x.first); //uynique heights
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                
                int sum = heights[i] + heights[j];
                if(i==j) {
                    // same item check its freqquemcy
                    sumCount[sum] += freq[heights[i]]/2;
                } else {
                    int f = min(freq[heights[i]], freq[heights[j]]);
                    sumCount[sum] +=f;
                }                
                // cout<<heights[i]<< " "<<heights[j]<<" "<<sum<<" "<<sumCount[sum]<<endl;

                c = max(c, sumCount[sum]);
            }
        }
        
        return c;
    }
};