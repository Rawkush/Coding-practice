struct comparator{
    bool operator()(pair<char,int>p1, pair<char,int>p2){
        return p1.second<p2.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto x:tasks){
            mp[x]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>,comparator> pq;
        for(auto x: mp) pq.push({x.first, x.second});
        queue<char> q;
        
        //create a queue with sorted data and push item in it
        for(int i=0; i<=n; i++){
          if(pq.empty()){
            q.push('.');
          }else{
            pair<char,int> p =pq.top();
            pq.pop();
            q.push(p.first);
          }
        }
        int count=0;
        while(!q.empty()){
          if(mp.size()<=0) break;
          count++;
          char ch = q.front();
          q.pop();
          cout<<ch;
          if(ch=='.'){
            pq.push({'.', -1});
          }else{
            mp[ch]--;
            if(mp[ch]<=0){
              pq.push({'.', -1});
              mp.erase(ch);
            }else  pq.push({ch, mp[ch]}); // push this back to priority queue
          }
          pair<char,int> tp = pq.top();
          pq.pop();
          q.push(tp.first);
        }
        return count;
    }
};