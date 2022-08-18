class Solution {
public:
    int climbStairs(int n) {
      int *mem = new int [n+4];
      mem[0]=0;
      mem[1]=1;
      mem[2]=2;
      for(int i=3; i<=n ; i++){
        mem[i] = mem[i-1]+mem[i-2];
      }

      int result = mem[n];
      delete []mem;
      return result;
    }
};

void clib(int n) {

  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 2;

  if(mem[n]) return mem[n];
  mem[n]=climb(n-1) + clim(n-2);
  return sum;
}


void clib(int n) {
{
  int arr[];
  ar[0]=0; arr[1]=1; arr[2]=2;

  for(int i=3; i<=n; i++){
    int sum = arr[i-1] + arr[i-2];
    arr[i]=sum;
  }
  return arr[n];
}