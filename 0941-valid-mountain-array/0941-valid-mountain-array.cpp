class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    if(arr.size()<=2) return false;
    int pi = 1; //peakIndex
    while(pi < arr.size()){
      if(arr[pi-1]<arr[pi]) pi++;
      else break;
    }
    // cout<<pi<<endl;
    if(pi==1) return false;
    // cout<<arr[pi-1]<<arr[pi]<<endl;
    // cout<< (arr[pi-1] <= arr[pi])<<endl;
    if(pi>=arr.size()) return false;
    if(pi >= arr.size()-1 && arr[pi-1] <=arr[pi] ){
      return false;
    } 
    while(pi < arr.size()){
      if(arr[pi-1] > arr[pi]) pi++;
      else return false;
    }

    return true;
  }
};