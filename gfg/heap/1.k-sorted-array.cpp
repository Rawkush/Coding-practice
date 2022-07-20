#include <bits/stdc++.h>
#define mdebug(x) cout << #x << " " << x << endl;
using namespace std;

string isKSortedArray(int arr[], int n, int k)
{
  priority_queue<pair<int, int> >pq;
  for (int i = 0; i < n; i++)
  {
    pq.push(make_pair(arr[i]*-1, i));
  }
  for (int i = 0; i < n; i++)
  {
    pair<int, int>p = pq.top();
    pq.pop();
    if(abs(i-p.second)>k) return "No";
  }
  return "Yes";
}

int main()
{
  int arr[] = {50, 24, 43};
  int size = 6;
  cout << isKSortedArray(arr, 3, 1);
  return 0;
}