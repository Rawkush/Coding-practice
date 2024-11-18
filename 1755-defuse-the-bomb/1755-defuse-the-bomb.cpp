class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(), 0);
        int n = code.size();

        // sliding window with size k,
        int sum=0, start=1, end=k;
        if(k==0) return res;
        if(k<0){
            end=n-1;
            start=n-abs(k);  // fo once step back => n-1, 2 step bacl n-2, k step back n-k
        }
        // sum of first k elements
        for(int i = start; i<=end; i++) sum+=code[i];

        //slide window and start updating
        for(int i=0; i<n; i++){
            res[i]= sum;
            end =(end+1)%n; //next item to windoe
            sum=sum-code[start]+code[end];
            //move last item of window
            start=(start+1)% n;
        }

      return res;
    }
};