#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
  char data;
  unordered_map<char, TrieNode *> children;
  bool isWord;
  TrieNode(char c)
  {
    this->data = c;
    isWord = false;
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

  void insert(string word)
  {
    TrieNode *current = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (current->children.count(word[i]) == 0)
      {
        current->children[word[i]] = new TrieNode(word[i]);
      }
      current = current->children[word[i]];
    }
    current->isWord = true;
  }

  bool search(string word)
  {
    TrieNode *current = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (current->children.count(word[i]) == 0)
        return false;
      current = current->children[word[i]];
    }
    return current->isWord;
  }

  bool startsWith(string prefix)
  {
    TrieNode *current = root;
    for (int i = 0; i < prefix.size(); i++)
    {
      if (current->children.count(prefix[i]) == 0)
        return false;
      current = current->children[prefix[i]];
    }
    return true;
  }
};

string reverse(string &word){
  string tmp = "" ;
  for(auto i: word){
    tmp = i +tmp;
  }
  return tmp;
}

void findPalindrome(vector<string> &words, Trie &trie, int idx, vector<vector<int>> &result){
  if(idx >= words.size()-1) return;
  for(int i=idx+1; i < words.size(); i++){
    if(trie.search(words[i]+words[idx])){
      vector<int> indexVector;
      indexVector.push_back(i);
      indexVector.push_back(idx);
      result.push_back(indexVector);
    }
    if(trie.search(words[idx]+words[i])){
      vector<int> indexVector;
      indexVector.push_back(idx);
      indexVector.push_back(i);
      result.push_back(indexVector);
    }
  }
  findPalindrome(words, trie, idx+1, result);
}

vector<vector<int>> palindromePairs(vector<string> &words){
  Trie trie;
  for(auto word: words){
    trie.insert(reverse(word));
  }
  vector<vector<int>> result;
  findPalindrome(words, trie, 0, result);
  return result;
}

int main()
{
  vector<string> words;
  words.push_back("abcd");
  words.push_back("dcba");
  words.push_back("lls");
  words.push_back("s");
  words.push_back("sssll");
  vector<vector<int>> index = palindromePairs(words);
  cout<<index.size()<<endl;
  for(auto pal: index){
    for(auto idx: pal){
      cout<<idx<<" ";
    }
    cout<<endl;
  }
  return 0;
}