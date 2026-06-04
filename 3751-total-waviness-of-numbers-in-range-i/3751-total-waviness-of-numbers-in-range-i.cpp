class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wave = 0;
        int st = max(100, num1);
        for(int i=st; i<=num2; i++) {
            string s = to_string(i);
            for(int i=1; i<s.size()-1; i++) {
                int a = s[i-1] - '0';
                int b = s[i] - '0';
                int c = s[i+1] - '0';
                if(b>a && b>c) wave++;
                else if(a>b && c > b) wave++;
            }
        }

        return wave;
    }
};