class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l =0; 
    int r = arr.size()-1;
    while(l<=r){
      int mid = l + (r-l)/2;
      cout<<"l "<<l<<" "<<"r "<<r<<endl;
      cout<<mid<<endl;
      if(arr[mid-1] < arr[mid] && arr[mid]>arr[mid+1]) return mid;
      if(arr[mid-1]<arr[mid]){
        l=mid;
      }else{
        r=mid;
      }
    }
    return -1;
  }
};