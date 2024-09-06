class Solution {
private:
    void dfs(string word, string targetWord, unordered_map<string, int>& map,
             vector<string>& path, vector<vector<string>>& ans) {

        if (word == targetWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        int ws = word.size();
        int clvl = map[word];
        string newWord;
        for(int i=0; i<ws; i++){
            newWord=word;
            for(char ch='a'; ch<='z'; ch++){
                newWord[i]=ch;
                if(map.count(newWord)>0 && clvl==map[newWord]+1){
                    path.push_back(newWord);
                    dfs(newWord, targetWord, map, path,  ans);
                    path.pop_back();
                }
            }
        }


    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        vector<vector<string>> ans;
        unordered_map<string, int> map;
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.count(endWord) <= 0)
            return ans; // target workd is not in word lsit

        queue<string> q;
        q.push({beginWord});
        map[beginWord] = 0;
        words.erase(beginWord);
        int ws = beginWord.size();
        while (!q.empty()) {
            string cw = q.front();
            int cl = map[cw]; // current level
            q.pop();
            string newWord;
            for (int i = 0; i < ws; i++) {
                newWord = cw;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    newWord[i] = ch;
                    if (words.count(newWord) > 0) {
                        words.erase(newWord);
                        q.push(newWord);
                        map[newWord] = cl + 1;
                    }
                }
            }
        }

        vector<string> path;
        /**
         * going from target to begin word as less number of path to
         * compute
         */
        path.push_back(endWord);
        dfs(endWord, beginWord, map, path, ans);

        return ans;
    }
};