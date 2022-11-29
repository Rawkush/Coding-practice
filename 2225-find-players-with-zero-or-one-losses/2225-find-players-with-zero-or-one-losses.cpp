#include<unordered_map>
typedef int lostCount;
typedef map<int, lostCount> players;
typedef map<int, lostCount>::iterator playerIterator;
class Solution {

public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      vector<vector<int>> result;
      players p;
      for(int i=0; i< matches.size(); i++){
        int winnerPlayer =  matches[i][0];
        int loserPlayer =  matches[i][1];
        p[winnerPlayer];
        p[loserPlayer] ++;
      }
      
      vector<int> playerLostOnce;
      vector<int> playerNeverLost;

      playerIterator it = p.begin();
      while(it!=p.end()){
        if(it->second==0){
          playerNeverLost.push_back(it->first);
        }
        if(it->second==1){
          playerLostOnce.push_back(it->first);
        }
        it++;
      }
      result.push_back(playerNeverLost);
      result.push_back(playerLostOnce);
      return result;
    }
};