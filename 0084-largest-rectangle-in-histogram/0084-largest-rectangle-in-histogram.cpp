class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    if(heights.size()<=0) return 0;
    // height ,width
    stack<pair<int, int>> st;
    int maxArea = 0;
    // int min = heights[0];
    for(int i=0; i<heights.size(); i++){
      if(st.empty()){
        st.push({heights[i], 1});
        maxArea = max(maxArea, heights[i]);
        continue;
      }
      int area = 0;
      // int len = st.top();
      int width = 0;
      while(!st.empty() && st.top().first >= heights[i] ){
        width+=st.top().second;
        int len = st.top().first;
        area = len * width;
        maxArea = max(maxArea, area);
        st.pop();
      }
      width++;
      st.push({heights[i], width});
      // int area = heights[i] * st.size();
      // maxArea = max(area, maxArea);
    }

    int area = 0;
    // int len = st.top();
    int width = 0;
    while(!st.empty()){
      width+=st.top().second;
      int len = st.top().first;
      area = len * width;
      maxArea = max(maxArea, area);
      st.pop();
    }

    return maxArea;
  }
};