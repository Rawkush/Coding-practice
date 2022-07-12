#include <iostream>
using namespace std;

bool backspaceCompare(string s, string t)
{
  //  if(s.length() != t.length()) return false;
  int i = s.length() - 1;
  int j = t.length() - 1;
  int skipS = 0;
  int skipT = 0;
  while (i >= 0 || j >= 0)
  {
    if (i>=0 && s[i] == '#')
    {
      skipS++;
      i--;
      continue;
    }
    // else if(skipS>0)  i--;
    if (j>=0 && t[j] == '#')
    {
      skipT++;
      j--;
      continue;
    }
    // else if(skipT>0)  j--;
    if (skipT > 0)
    {
      while (skipT > 0)
      {
        if (j>=0 && t[j] == '#')
          break;
        skipT--;
        j--;
      }
      continue;
    }
    if (skipS > 0)
    {
      while (skipS > 0)
      {
        if (i>=0 && s[i] == '#')
          break;
        skipS--;
        i--;
      }
      continue;
    }
    if (i< 0 && j>=0) return false;
    if(j<0 && i>=0) return false;
      if (s[i--] != t[j--])
        return false;
  }
  return true;
}
int main()
{
  /*printf
 "bxj##tw"
"bxo#j##tw"

"bxj##tw"
"bxj###tw"
  */
  string s = "bxj##tw";
  string t = "bxj###tw";
  cout << backspaceCompare(s, t);
  return 0;
}