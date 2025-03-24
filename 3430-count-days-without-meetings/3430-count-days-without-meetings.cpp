struct comparator{
  bool operator()(vector<int>&a, vector<int>&b){
    return a[0] >b[0];
  }
};
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
      sort(meetings.begin(), meetings.end());
      int m= meetings.size();
      int prevEnd = 0;
      int count=0;
      for(int i=0; i<m; i++){
        if(prevEnd < meetings[i][0] ){
          count+=meetings[i][0]-(prevEnd+1);
        }
        if(prevEnd<meetings[i][1]) prevEnd=meetings[i][1];
      }
      if(prevEnd<days) count+=days-prevEnd;
      return count;
    }
};