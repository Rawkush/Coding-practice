class Solution {
public:
/**
    * our sliding window size is k,
    * since we can pick only from start or end, that means we will have continuous array, assuming if the start and end are connected, like there is cycle
    * only first k and k elemenst  will be used at any case, we can never have a case where other item can come into play as we can pick only from start or end
    *
    */
  int maxScore(vector<int>& cardPoints, int k) {
    int sum=0;
    for(int i=0; i<k; i++) sum +=cardPoints[i]; //sum if all elements are picked from start
    
    int res=sum;
    // check if we move the window, i.e take one element from back will we get more score
    for(int i=k-1, j=1; i>=0; i--, j++){
      //slided window toward left 
      sum-=cardPoints[i]; ///remove this item from window
      sum+=cardPoints[cardPoints.size()-j]; //add this item to window
      res = max(res, sum); // check if max with current element
    }
    return res;
  }
};