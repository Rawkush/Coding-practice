class Solution {
public:
  // void print(stack<int> st){
  //   while(!st.empty()){
  //     cout<<st.top()<<" ";
  //     st.pop();
  //   }
  //   cout<<endl;
  // }
  vector<int> canSeePersonsCount(vector<int>& heights) {
    stack<int> st;
    vector<int> res;
    if(heights.size()<=0)   return res;
    // if(heights.size()==1){
    //   res.push_back(0);
    //   return res;
    // }
    // if(heights.size()==2){
    //   res.push_back(1);
    //   res.push_back(0);
    //   return res;
    // }

    // array is > 2
    // res.push_back(0);
    // st.push(heights[heights.size()-1]);
    for(int i=heights.size()-1; i>=0; i--){
      int h = heights[i];
      // print(st);
      if(st.empty()){
        st.push(h);
        res.push_back(0);
        continue;
      }
      
      if(st.top()> h){
        res.push_back(1);
        st.push(h);
        continue;
      }

      int count = 0;
      while(!st.empty() && st.top()<=h){
        count++;
        st.pop();
      }
      if(!st.empty()) count++;
      res.push_back(count);
      st.push(h);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};