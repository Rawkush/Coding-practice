class Solution {
public:
// using sliding window
  // int minimumCardPickup(vector<int>& cards) {
  //   int mn = INT_MAX;
  //   int l=0,r=0;
  //   unordered_map<int,int>mp;
  //   while(r<cards.size()){
  //     mp[cards[r]]++;
  //     if(mp[cards[r]]>1){
  //       // duplicate found
  //       //remove all unnecessary elements
  //       while(cards[l]!=cards[r] || mp[cards[r]]>2){
  //         mp[cards[l]]--;
  //         if(mp[cards[l]]<=0) mp.erase(cards[l]);
  //         l++;
  //       }
  //       mn = min(mn, r-l+1);
  //     }
  //     r++;
  //   }

  //   return mn == INT_MAX ? -1 : mn;
  // }

  int minimumCardPickup(vector<int>& cards) {
    int mn = INT_MAX;
    int l=0,r=0;
    unordered_map<int,int>mp;
    for(int i=0; i<cards.size(); i++){
      if(mp.count(cards[i])==0){
        mp[cards[i]] = i;
      }else{
        int lastIdx = mp[cards[i]];
        mn = min(mn, i-lastIdx +1);
        mp[cards[i]] = i;
      }
    }
    return mn == INT_MAX ? -1 : mn;
   }
};