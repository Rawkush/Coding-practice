// normal recursion way withour memorization
int countMinStepsToOne(int n)
{
  if (n <= 1)
    return 0;
  // Write your code here
  int minStep = INT_MAX;
  if (n % 3 == 0)
    minStep = min(minStep, countMinStepsToOne(n / 3));
  if (n % 2 == 0)
    minStep = min(minStep, countMinStepsToOne(n / 2));
  minStep = min(minStep, countMinStepsToOne(n - 1));
  return 1 + minStep;
}

// with memorization

#include <unordered_map>

unordered_map<int, int> mp;

int countStepsToOne(int n)
{
  if (n <= 1)
    return 0;
  // Write your code here
  int minStep = INT_MAX;
	if(mp.find(n)!=mp.end()) return mp[n];

  if (n % 3 == 0){
      minStep = min(minStep, countStepsToOne(n / 3));
  }
  if (n % 2 == 0){
      minStep = min(minStep, countStepsToOne(n / 2));
  }
  minStep = min(minStep, countStepsToOne(n - 1));

  mp[n]=1+minStep;
  return 1 + minStep;
}

// using Dynamic Programming

int countStepsToOne(int n){
  if(n==1) return 0;
  int *minSteps= new int[n+1];
  minSteps[1]=0;

  for(int i=2; i<=n ; i++){
    int minPath = INT_MAX;
    minPath = min(minPath, minSteps[i-1]);
    //for n/2
    if(i%2==0) minPath = min(minPath, minSteps[i/2]);
    if(i%3==0) minPath = min(minPath, minSteps[i/3]);
    minSteps[i] = 1+minPath;
  }
  int result = minSteps[n];
  delete []minSteps;
  return result;
}
