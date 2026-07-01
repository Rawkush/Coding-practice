class Solution {
public:
    bool isVowel(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    void print(unordered_map<char,int> &mp) {
        for(auto x: mp) {
            cout<<x.first<< " "<<x.second<<endl;
        }
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char,int> mp;
        long long l=0, r=0;
        long long total =0;
        long long consonantCount = 0;
        long long prefixCount = 1;
        while(r<word.size()) {
            if(isVowel(word[r])) mp[word[r]]++;
            else consonantCount++;    
            // cout<<l<<" "<<r<<" "<<consonantCount<<" "<<total<<endl;
        
            // shrink the window
            if(consonantCount>k){
                //shrink the windowuntil 
                while(l<r && consonantCount >k ) {
                    if(isVowel(word[l])) {
                        mp[word[l]]--;
                        if(mp[word[l]]==0) mp.erase(word[l]);
                        // else if(mp.size()==5) {
                        //     total +=prefixCount;
                        // }
                        l++;
                    } else {
                        consonantCount--;
                        l++; 
                        break;
                    }
                }
                // if(consonantCount == k && mp.size()==5) total+=prefixCount;
                prefixCount =1;
            }
            while(consonantCount == k && mp.size()==5) {
                if(!isVowel(word[l]) || mp[word[l]]<=1) break;
                mp[word[l]]--;
                prefixCount++;
                l++;
            } 
            // cout<<"DAS "<<l<<" "<<r<<" "<<consonantCount<<" "<<total<<endl;
            if(consonantCount == k && mp.size()==5) {
                // cout<<"asdc "<<prefixCount<<endl;
                total += prefixCount;
            } 
            r++;
        }
        // print(mp);
        // cout<<l<<" "<<r<<" "<<consonantCount<<" "<<total;
        while(consonantCount >= k && l<r && mp.size()==5) {
            if(isVowel(word[l])) {
                mp[word[l]]--;
                if(mp[word[l]]==0) break;
            } else {
                consonantCount--;
            }
            if(consonantCount == k && mp.size()==5) total++;
            l++;
        }
        return total;
    }
};