class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    long long atLeastK(string &word, int k) {
        int n = word.size();

        unordered_map<char, int> mp;
        int consonants = 0;
        int left = 0;

        long long ans = 0;

        for (int right = 0; right < n; right++) {

            if (isVowel(word[right]))
                mp[word[right]]++;
            else
                consonants++;

            while (mp.size() == 5 && consonants >= k) {

                // Every substring starting before 'left'
                // and ending at 'right' is also valid.
                ans += (n - right);

                if (isVowel(word[left])) {
                    mp[word[left]]--;
                    if (mp[word[left]] == 0)
                        mp.erase(word[left]);
                } else {
                    consonants--;
                }

                left++;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};