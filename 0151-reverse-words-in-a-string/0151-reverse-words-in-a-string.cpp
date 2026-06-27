class Solution {
public:
    void removeSpace(string &s) {
        //remvoe space from end 
        int i=0, j=s.size();

        while(j>0 && s[j-1]==' ') j--;
        s.resize(j);

        reverse(s.begin(), s.end());
        j=s.size();
        while(j>0 && s[j-1]==' ') j--;
        s.resize(j);

        // undo
        reverse(s.begin(), s.end());

        j=0;
        while(i<s.size()) {
            if(s[i]==' ') {
                s[j] = s[i];
                i++;
                if(j>0)j++;
                while(i<s.size() && s[i]==' ') i++;
            } else {
                s[j] = s[i];
                i++;
                j++;
            }
        }
        s.resize(j);
    }
    string reverseWords(string s) {
        removeSpace(s);
        // cout<<s<<endl;
        reverse(s.begin(), s.end());
        // cout<<s;
        int p=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==' ' || i==s.size()-1) {
                if(i==s.size()-1) i++;
                reverse(s.begin() + p, s.begin() + i);
                p = i+1;
            }
        }
        return s;
    }
};