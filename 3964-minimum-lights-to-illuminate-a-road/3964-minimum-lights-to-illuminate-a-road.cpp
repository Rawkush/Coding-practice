class Solution {
public:
    void fillStreet(vector<int>& arr, int idx, int v) {
        int l = max(0, idx-v);
        int r = min((int)arr.size()-1, idx+v);
        // cou  t<<l<<" "<<r<<endl;
        for(int i=l; i<=r; i++ ) {
            if(arr[i]!=-1) i = arr[i];
            if(arr[i] >= r) break;
            arr[i] = r; // light
        }
    }
    int minLights(vector<int>& lights) {
        vector<int> arr(lights.size(), -1);
        for(int i=0; i<lights.size(); i++) {
            if(lights[i] ==0 ) continue;
            fillStreet(arr, i, lights[i]);
        }

        //now we fil remaining dark sopts
        int count=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]!=-1) continue;
            if(arr[i]==-1 && i+1<arr.size() && arr[i+1]==-1) {
                arr[i]=1;
                arr[i+1] =1;
                if(i+2 < arr.size()) arr[i+2] = 1;
                count++;
            } else{
                arr[i] = 1;
                count++;
            }

        }
        return count;
    }

};