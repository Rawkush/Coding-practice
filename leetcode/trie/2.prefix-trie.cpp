#include <unordered_map>
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
