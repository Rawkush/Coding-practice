class Solution {
public:
    string removeUnnecessaryStartingPrefix(string &s) {
        for(int i=0; i<s.size(); i++) {
            if(!isOp(s[i])) return s.substr(i, s.size());
        }
        return "";
    }
    string removeUnnecassyRotation(string &s) {
        string cleaned;
        for (char c : s) {
            if (c == '%' && !cleaned.empty() && cleaned.back() == '%') {
                cleaned.pop_back();
            } else {
                cleaned.push_back(c);
            }
        }
        return cleaned;
    }
    long long getStringLen(string &s, vector<long long>&sl) {
        long long i=0, len =0;
        for(auto x:s) {
            if(x =='*' && len >0 ) len--;
            else if( x == '%' ); //do not do anyhting as len does ont change on reverse
            else if( x == '#') len*=2;
            else len++;
            sl[i++] = len;
        }
        return len;
    }

    bool isOp(char c) {
        return c == '*' || c=='#' || c== '%';
    }
    
    char helper(string &s, long long k, int idx, vector<long long> &sl) {
        if(idx<0) return '.';
        long long currLen = sl[idx];
        if (k >= currLen) return '.';

        if(!isOp(s[idx])) {
            if( k == currLen-1 ) return s[idx];
            return helper(s, k, idx-1, sl);
        }

        if(s[idx]=='#') {
            // check prev element size to find out where the k lies
            long long prevLen = idx>0 ? sl[idx - 1] : 0;
            //it lies in previous string operation response
            if(prevLen > k) return helper(s, k, idx-1, sl);
            //else it means that char lies in current array range only, 
            // now we need to map current character to left array, which is 
            // arr + arr => so we can just delete tht first arr as we
            // know answer is in second arr, 
            return helper(s, k-prevLen , idx-1, sl);
        }
        //ignoring as when calculting length we already removed it from response
        // so current element at k is the actual anser we do not need to delete
        if(s[idx]=='*') {
            return helper(s, k, idx-1, sl);
        }
        //reverse string 
        if(s[idx] == '%') {
            return helper(s, currLen-k-1, idx-1,sl);
        }

        return '.';
    }
 
    char processStr(string s, long long k) {
        s = removeUnnecessaryStartingPrefix(s);
        vector<long long> sl(s.size());

        s = removeUnnecassyRotation(s);
        long long len = getStringLen(s, sl);

        int idx = 0;
        for(int i=0; i<s.size(); i++) {
            // find out the max index if any from where the string becomes 0
            if(sl[i] == 0) idx = i;
        }
        /**
        * we can safely remove first character from the string
        */

        s = s.substr(idx, s.size());
        // cout<< s <<" "<<idx<<endl;
        /**
        * if this new substring has prefixes, remove those
        */
        s = removeUnnecessaryStartingPrefix(s);
        // cout<<s<< endl;

        /***
        * since the input string ha chnaged we will need to recompute the string length array
        *
        */
        vector<long long> stringLengthArr2(s.size());
        long long newStringLen = getStringLen(s, stringLengthArr2);

        if(k>=newStringLen) return '.';

        return helper(s, k, s.size()-1, stringLengthArr2);
    }
};