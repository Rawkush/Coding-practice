#include <iostream>
#include<vector>
#include<climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSumfound=INT_MIN;
    int continuosSumfound=0;
    for(int i=0; i<nums.size(); i++){
        continuosSumfound += nums[i];
        if(continuosSumfound>maxSumfound)
            maxSumfound =continuosSumfound;
        if(continuosSumfound<0)
            continuosSumfound =0;
    }
    return maxSumfound;
}
int main(){
    vector<int> array{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(array);
    return 0;
}