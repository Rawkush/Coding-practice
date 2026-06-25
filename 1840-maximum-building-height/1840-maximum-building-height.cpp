class Solution {
public:

    void print(map<int, int> &heights) {
        for(auto x: heights) cout<< x.first<< " " <<x.second<<" "<<endl;
        cout<<endl;
    }

    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // vector<int> arr(n, 0);
        // unordered_map<int,int> mp;
        // vector<int> restrictionIdx;
        // for(auto x:restrictions) {
        //     mp[x[0]-1] = x[1]; // converting 1 based indexing to 0 based indexing by subtracting x[0] -1
        // }

        sort(restrictions.begin(), restrictions.end());
        map<int, int> heights; // stores size bewtwwen two restrictions

        int prev = 0; //prev restricion idx, at 0  restiction of 0
        for(auto x: restrictions) {
            //restriciton is placed at index x so heigth will be prevIdx + x
            int rIdx = x[0] - 1; // converting it to 0 based indexing for simplicity
            int rVal = x[1];

            int previousRestricionBuildingHeight = heights[prev];
            int h1 = previousRestricionBuildingHeight + (rIdx-prev);
            
            // height Diff is +ve it m eans next building can be bigger
            heights[rIdx] = min(rVal, h1);       
            prev = rIdx;
        }
        // print(heights);

        // do the same from reverse
        if(heights.count(n-1)<=0) {
            int distance = n-prev-1; // as we shifted the idx ny 1
            heights[n-1] = heights[prev] + distance;
        }
        prev = n-1; // 0 based indexing we shifted by 1
        for(int i=restrictions.size()-1; i>=0; i--) {
            auto x = restrictions[i];
            //restriciton is placed at index x so heigth will be prevIdx + x
            int rIdx = x[0] - 1; // converting it to 0 based indexing for simplicity
            int rVal = x[1];

            int previousRestricionBuildingHeight = heights[prev];
            int h1 = previousRestricionBuildingHeight + (prev-rIdx);
            
            // height Diff is +ve it m eans next building can be bigger
            heights[rIdx] = min(heights[rIdx], min(rVal, h1));
            prev = rIdx;
        }
        // print(heights);

        int ans =0;
        int prevIdx = 0;
        int previousHeight =0;
        int first = true;
        for(auto &x: heights) {
            int ph = previousHeight;
            int h = x.second;
            int distance = x.first - prevIdx;
            //distance bewtween two buildind is d
            while(distance>0) {
                // if(distance == 1) break;
                if(abs(ph-h)>1) {
                    if(ph>h) h++;
                    else ph++;
                    distance--;
                } else {
                    if(distance == 1) { 
                        distance--; 
                    }                              // was: { ph++; distance--; }
                    else if(ph == h) { ph++; h++; distance -= 2; }
                    else { if(ph > h) h++; else ph++; distance--; } // equalize first
                }
            }
            ans = max(ans, max(h, ph));
            previousHeight = x.second;
            prevIdx = x.first;
        }
        // if(heights.size()==1) ans = max(ans, heights[n-1]); // don't forget the last anchor itsel
        return ans;
    }
};