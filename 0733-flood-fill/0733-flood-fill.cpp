class Solution {
public:

  void helper(vector<vector<int> >&image, int sr, int sc, int color, int targetPixel){
    if(sr>= image.size() || sc>= image[0].size()) return;
    if(sr<0 || sc<0) return;
    if(image[sr][sc]!=targetPixel) return;
    // update all elements of same value
    
    image[sr][sc]=color;

    //left
    helper(image, sr, sc-1, color, targetPixel);
    //right
    helper(image, sr, sc+1, color, targetPixel);
    //up
    helper(image, sr-1, sc, color, targetPixel);
    // down
    helper(image, sr+1, sc, color, targetPixel);
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int color)
  {
    int targetPixel = image[sr][sc];
    if(color==targetPixel) return image; // no point in repalcing it withitself
    helper(image,sr,sc, color, targetPixel);
    return image;
  }
};