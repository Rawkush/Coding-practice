#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> pq;
      for(int i=0; i<stones.size(); i++) {
        pq.push(stones[i]);
      }
      while(!pq.empty()){
        if(pq.size()==1) return pq.top();
        int stone1 = pq.top();
        pq.pop();
        int stone2 = pq.top();
        pq.pop();
        if(abs(stone1-stone2) ==0) continue;
        else pq.push(abs(stone1-stone2));
      }
      return 0;
    }
};