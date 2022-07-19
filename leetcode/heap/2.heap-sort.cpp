#include<iostream>
#include<vector>

using namespace std;

    void removeMax(vector<int>&nums, int size){
      //swap max to last, then assume it was deleted from heap
      if(size==0)return;
      swap(nums[0], nums[size-1]);

      //down heapify
      int parentIndex = 0;
      while(parentIndex < size-1){
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        int maxData = nums[parentIndex];
        if(leftChildIndex >= size-1) break;
        if(rightChildIndex >= size-1){
          maxData = max(nums[parentIndex], nums[leftChildIndex]);
        }else maxData = max(nums[leftChildIndex], max( nums[rightChildIndex], nums[parentIndex]));
        if(maxData == nums[parentIndex]) break;
        if(maxData == nums[leftChildIndex] ){
          swap(nums[parentIndex], nums[leftChildIndex]);
          parentIndex = leftChildIndex;
        }else if(maxData == nums[rightChildIndex]){
          swap(nums[parentIndex], nums[rightChildIndex]);
          parentIndex = rightChildIndex;
        }
      }
    }
    vector<int> sortArray(vector<int>& nums) {
      int lastIndex=1;
     //create a max heap
      for(int i=1; i< nums.size(); i++){
        int childIndex=i;
        while(childIndex>0){
          int parentIndex = (childIndex-1)/2;
          if(nums[parentIndex]<nums[childIndex]){
            swap(nums[parentIndex], nums[childIndex]);
          }else break;
          childIndex = parentIndex;
        }
      }

      //remove max items from maxheap and push it to last of the array
      for(int i=0; i<= nums.size(); i++){
        removeMax(nums, nums.size()-i);
      }
      return nums;
    }

    void print(vector<int> nums){
      for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<endl;//>>
      }
    }
int main(){

  vector<int> v={1,2,3,4,5,6,7,8,9,10,11,12,13};
  sortArray(v);
  print(v);
  return 0;
}