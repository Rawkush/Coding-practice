class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return abs((n*n) - (n*n +n));
    }
};