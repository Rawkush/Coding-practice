#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;
class TrieNode{
public:
  char data;
  TrieNode **children;
  bool isTerminal;
  TrieNode(char data){
    this->data = data;
    children = new TrieNode*[26];
    isTerminal = false;
    for(int i = 0; i < 26;i++){
      children[i] = NULL;
    }
  }
};

class Trie{
  TrieNode *root;
  public:
  Trie(){
    root = new TrieNode('\0');
  }

  void addWord(string s){
    TrieNode *head=root;
    for(int i = 0; i <s.size(); i++){
      if(head->children[s[i]-'a'] == NULL){
        head->children[s[i]-'a'] = new TrieNode(s[i]);
      }else{
        head=head->children[s[i]-'a'];
      }
    }
    head->isTerminal=true;
  }

  bool searchWord(string s){
    TrieNode *head =root;
    for(int i=0;i< s.size(); i++){
      if(head->children[s[i]-'a']== NULL) return false;
      head = head->children[s[i]-'a'];
    }
    return head->isTerminal;
  }
};

// bool wordBreak(string s, vector<string>& wordDict) {
//   unordered_map<string, int> map;
//   for(auto word: wordDict){
//     map[word]++;
//   }
//   unordered_map<string, bool> mem;
//   return wordBreakHelper(s, map, mem);
// }

int main(){
  Trie myTrie;
  myTrie.addWord("leet");
  myTrie.addWord("code");
  cout<<myTrie.searchWord("leet");
  return 0;
}