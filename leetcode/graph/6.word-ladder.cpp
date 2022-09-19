
bool isAdjacent(string& word1, string &word2){
  int countDiff =0;
  for(int i=0;i<min(word1.size(), word2.size());i++){
    if(word1[i] != word2[i]) countDiff++;
  }
  if(countDiff>1 || countDiff==0) return false;
  return true;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList){
  unordered_map<string, vector<string>> words;
  unordered_map<string, bool> isVisited;

  //first find all edges for beginWord
    for(int j = 0; j< wordList.size(); j++){
      if(isAdjacent(beginWord, wordList[j])){
        words[beginWord].push_back(wordList[j]);
      }
    }

  for(int i = 0; i <wordList.size(); i++){
    for(int j = 0; j< wordList.size(); j++){
      if(i==j) continue;
      if(isAdjacent(wordList[i], wordList[j])){
        words[wordList[i]].push_back(wordList[j]);
      }
    }
  }

  int minPath =0;
  queue<string> q;
  q.push(beginWord);
  isVisited[beginWord]=true;
  while(!q.empty()){
    int lvlLength = q.size();
    tmpPath++;
    for(int i=0; i<lvlLength; i++){
      string currentWord = q.front();
      q.pop();
      vector<string> adjacentWords = words[currentWord];
      for(int i = 0; i < adjacentWords.size(); i++){
        if(isVisited[adjacentWords[i]]) continue;
        isVisited[adjacentWords[i]]=true;
        if(endWord==adjacentWords[i]){
          minPath = min(minPath, tmpPath) +1;
          return minPath;
        }
        q.push(adjacentWords[i]);
      }
    }
  }
  if(minPath==INT_MAX) return 0;
}