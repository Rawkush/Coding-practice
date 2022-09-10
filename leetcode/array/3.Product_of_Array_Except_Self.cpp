#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums{1,2,3,4};
    vector<int> outputs;
    int product=1;
    int count_zero=0;
    for(int i=0; i<nums.size();i++){
        outputs.push_back(product);
        product*=nums[i];
    }
    product=1;
    for(int i=nums.size()-1; i>=0;i--){
        outputs[i]*=product;
        product*=nums[i];
    }
    for(int i=0; i<nums.size();i++){
        cout<<" "<<outputs[i];
    }
    return 0;
}
