class Solution {
public:
    int tribonacci(int n) {
      if(n<=0) return 0;
      if(n<=2) return 1;
      // tr(n-1) +tr(n-2) + tr(n-3)
      int t1=0;
      int t2=1;
      int t3=1;
      int sum =0;
      while(n>2){
        sum = t1 +t2 +t3;
        t1=t2;
        t2=t3;
        t3=sum;
        n--;
      }
      return sum;
    }
};