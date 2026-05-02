class Solution {
public:
    bool isOverlap(int x1, int y1, int x2, int y2) {
        if( y1 >= x2 ) return true;
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i=0; i<intervals.size(); i++) {
            if(i==0) {
                res.push_back({intervals[i][0], intervals[i][1]});
                continue;
            }
            int x1= res[res.size()-1][0];
            int y1= res[res.size()-1][1];
            int x2 = intervals[i][0];
            int y2 = intervals[i][1];
            if(isOverlap(x1,y1,x2,y2)) {
                res[res.size()-1][1] = max(y1, y2);
            } else {
                res.push_back({x2,y2});
            }
        }
        return res;
    }
};