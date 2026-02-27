struct Compare {
    bool operator() (int a, int b) {
        int aa = a, bb =b;
        int c1 =0,c2 =0;
        while(a>0) {
            a = (a&(a-1));
            c1++;
        }
        while(b>0) {
            b = (b&(b-1));
            c2++;
        }
        if(c1 == c2) return bb > aa;
        return c2 > c1;
    }
};
class Solution {
public:

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), Compare());
        return arr;
    }
};