struct comparator{
    bool operator()(pair<int,pair<int,int>> &i, pair<int,pair<int,int>> &j){
        return i.first > j.first;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, comparator> pq;
        for(int i=0; i<matrix.size(); i++){
            pq.push({matrix[i][0], {i, 0}});
        }
        int n= matrix[0].size();
        int count =0;
        while(!pq.empty()){
            pair<int, pair<int,int>> p = pq.top();
            pq.pop();
            count++;
            if(count==k) return p.first;
            int i = p.second.first;
            int j= p.second.second;
            if(j+1<n) pq.push({matrix[i][j+1], {i, j+1}}); 
        }
       
        return 0;
    }
};