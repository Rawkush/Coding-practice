#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class TrieNode
{
public:
  char data;
  unordered_map<char, TrieNode *> children;
  bool isTerminal;
  TrieNode(char data)
  {
    this->data = data;
    isTerminal = false;
  }
};

class Trie
{
public:
  TrieNode *root;
  Trie()
  {
    root = new TrieNode('\0');
  }

  void addWord(string s)
  {
    TrieNode *head = root;

    for (int i = 0; i < s.size(); i++)
    {
      if (head->children.count(s[i]) == 0)
      {
        head->children[s[i]] = new TrieNode(s[i]);
      }
      head = head->children[s[i]];
    }
    head->isTerminal = true;
  }

  bool searchWord(string s)
  {
    TrieNode *head = root;
    for (int i = 0; i < s.size(); i++)
    {
      if (head->children[s[i] - 'a'] == NULL)
        return false;
      head = head->children[s[i] - 'a'];
    }
    return head->isTerminal;
  }
};

bool wordBreakHelper(string s, Trie &trie, int i, unordered_map<int, bool> &mem)
{

  if (mem.find(i) != mem.end())
    return mem[i];
  if (i >= s.size())
    return true;
  int startIndex = i;
  auto head = trie.root;
  for (int j = i; j < s.size(); j++)
  {
    if (head->children.find(s[j]) == head->children.end())
    {
      mem[i] = false;
      return false;
    }
    head = head->children[s[j]];
    if (head->isTerminal && wordBreakHelper(s, trie, j + 1, mem))
    {
      mem[j] = true;
      return true;
    }
  }
  mem[i] = false;
  return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
  Trie trie;
  unordered_map<int, bool> mem;
  for (auto word : wordDict)
  {
    trie.addWord(word);
  }
  return wordBreakHelper(s, trie, 0, mem);
}

int main()
{
  vector<string> wordDict;
  wordDict.push_back("apple");
  wordDict.push_back("pen");
  cout << wordBreak("applepenapple", wordDict);
  return 0;
}