#include<iostream>
#include <vector>
using namespace std;



vector<vector<int>> subsets(vector<int>& nums) {

}
int main(){
    vector<int> nums{1,2,3};

    vector<vector<int>> res=subsets(nums);

    // Print result
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
