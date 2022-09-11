#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int> >&image, int sr, int sc, int color, int targetPixel){
  if(sr>= image.size() || sc>= image[0].size()) return;
  if(sr<0 || sc<0) return;
  if(image[sr][sc]!=targetPixel) return;
  // update all elements of same value

  //left
  helper(image, sr, sc-1, color, targetPixel);
  //right
  helper(image, sr, sc+1, color, targetPixel);
  //up
  helper(image, sr-1, sc, color, targetPixel);
  // down
  helper(image, sr+1, sc, color, targetPixel);
  image[sr][sc]=color;
}

vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int color)
{
  int targetPixel = image[sr][sc];
  helper(image,sr,sc, color, targetPixel);
  return image;
}