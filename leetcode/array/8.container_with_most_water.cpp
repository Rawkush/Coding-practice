#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<set>
#include<algorithm>

using namespace std;

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
int main(){
    vector<int> array{1,8,6,2,5,4,8,3,7};
    cout<<maxArea(array)<<endl;
    return 0;
}