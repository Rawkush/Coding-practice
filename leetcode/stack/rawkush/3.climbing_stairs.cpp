class Solution {
public:
    int count=0;
    int climbStairs(int n) {

      /** recursive solution */
      // int climbStairs(int n) {
			// if(n<=2) return n;
			// int count1 = climbStairs(n-1);
			// int count2 = climbStairs(n-2);
			// return count1+count2;  // fibonacci f(n-1) +f(n-2) = f(n)


      int x = 0, y = 1, z = 0;
      for (int i = 0; i < n; i++) {
         z = x + y;
        x = y;
        y = z;
      }
      return z;
    }
};