class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words;
        for(auto x:wordList) words.insert(x);
        queue<string> q;
        q.push({beginWord});
        int count =1;
        while(!q.empty()){
            int ls = q.size();
            for(int i=0; i<ls; i++){
                string cw = q.front();
                q.pop();
                if(cw==endWord) return count;
                for(int i=0; i<cw.size(); i++){
                    string newWord = cw;
                    for(char ch='a'; ch<='z'; ch++){
                        newWord[i]=ch;
                        if(newWord==cw) continue;
                        if(words.count(newWord)>0){
                            q.push(newWord);
                            words.erase(newWord);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};