#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;
    for(int i =0; i< tickets.size(); i++){
     if(k>=i){
        time+=min(tickets[i], tickets[k]);
     }
     if(i>k){
      time+=min(tickets[i], tickets[k]-1);
     }
    }
    return time;
  }
};