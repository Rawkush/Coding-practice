class Solution {
public:
    bool isValid(int n) {
        if(n==1 || n==0 || n==8 ) return false;
        if(n==6 || n==9 || n==2 || n==5) return true;
        return false;
    }
    bool isBad(int n) {
        if(n==3 || n==7 || n==4) return true;
        return false;
    }
    int rotatedDigits(int n) {
        if(n<=1) return 0;
        // if(n<10) return isValid(n) ? 1 : 0;
        int tn =n;
        bool valid=false;
        while(tn>0) {
            int r = tn%10;
            tn=tn/10;
            if(isBad(r)) {
                valid=0;
                break;
            }
            valid= valid || isValid(r);
        }
        
        return rotatedDigits(n-1) +(valid?1:0);
    }
};