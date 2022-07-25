#include<queue>

class Comparator{
  public:
  bool operator() (pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first;
  }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      priority_queue<pair<int, int>,vector<pair<int,int>>, Comparator> pq;
      vector<string> output;
      for(int i=0; i<score.size(); i++){
        pq.push(make_pair(score[i],i));
        output.push_back("1");
      }
      int i=1;
      while(!pq.empty()){
        pair<int, int> top =pq.top();
        pq.pop();
        if(i==1){
          output[top.second]="Gold Medal";
        }else
        if(i==2){
          output[top.second] ="Silver Medal";
        }else
        if(i==3){
          output[top.second]="Bronze Medal";
        }else{
          output[top.second]=to_string(i);
        }
        i++;
      }
      return output;
    }
};