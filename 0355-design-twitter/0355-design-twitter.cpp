class Twitter {
public:
    unordered_map<int, list<pair<int,int>>> userPosts; //
    unordered_map<int, set<int>> userFollowers;
    int count =0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        list<pair<int,int>> &posts = userPosts[userId];
        if(posts.size()>=10) posts.pop_front();
        posts.push_back({tweetId, count});
        count++;
    }
    

    struct Compare {
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            return a.second < b.second;
        }
    };


    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            Compare
        > pq;
        for(auto p : userPosts[userId]) pq.push(p); // user post himself
        set<int> followers = userFollowers[userId];
        for(auto x:followers) {
            for(auto p: userPosts[x]) pq.push(p);
        }
        int i=0;
        while((i++)<10 && !pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userFollowers[followerId].count(followeeId)<=0) return;
        userFollowers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */