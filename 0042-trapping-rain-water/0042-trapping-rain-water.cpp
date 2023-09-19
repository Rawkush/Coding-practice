class Solution {
public:
  int trap(vector<int>& height) {
    if(height.size()<3) return 0;
    stack<pair<int,int>> st; //height, width
    int tw = 0; // initial total water 
    for(int i=0; i<height.size(); i++){
      if(st.empty()){
        st.push({height[i], 1});
        continue;
      }
      if(st.top().first > height[i]){
        st.push({height[i], 1});
        continue;
      }
      int count =1;
      // if height > left, therefore water is stored
      while(!st.empty() && height[i] >= st.top().first){
        pair<int,int> mp = st.top();
        st.pop();
        if(st.empty()) break;
        pair<int, int> lp = st.top();
        if(lp.first < height[i]){
         lp.second+=mp.second;
         st.pop();
         st.push(lp);
        }else{
          count+=mp.second;
        }
        int h = min(lp.first, height[i]) - mp.first;
        int w = mp.second;
        tw+=h*w;
      }

      if(st.empty()){
        st.push({height[i],1});
      }
      else st.push({height[i], count});

    }
    return tw;
  }
};