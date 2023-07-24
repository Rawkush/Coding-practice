class Solution {
public:
    int max(int a, int b){
        if( a> b)
            return a;
        else return b;
    }
    int min(int a, int b){
        if(a<b)
            return a;
        else return b;
    }
    int maxArea(vector<int>& height) {
    int area = 0;
    int start = 0;
    int end = height.size()-1;
    for (int i = start; start < end; i++){
        area=max(area,(min(height[start], height[end]))*(end-start));
        if(height[start]>height[end])
            end--;
        else
            start++;
    }
    return area;
    }
};