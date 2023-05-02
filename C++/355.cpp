class Twitter {
public:
    stack<pair<int, int>> post;
    unordered_map<int, vector<int>> following;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        post.push({userId, tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> recent;
        vector<pair<int, int>> pop_out;
        vector<int> f = following[userId];
        int cnt = 0;
        while(cnt < 10 && !post.empty()){
            pair<int, int> p = post.top();
            pop_out.push_back(p);
            post.pop();
            if(p.first == userId || find(f.begin(), f.end(), p.first) != f.end()){
                recent.push_back(p.second);
                cnt++;
            }
        }
        for(int i = pop_out.size() - 1; i >= 0; i--){
            post.push(pop_out[i]);
        }
        return recent;
    }
    
    void follow(int followerId, int followeeId) {
        if(find(following[followerId].begin(), following[followerId].end(), followeeId) == following[followerId].end()){
            following[followerId].push_back(followeeId);
        }
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int>::iterator it = find(following[followerId].begin(), following[followerId].end(), followeeId);
        if(it != following[followerId].end())
            following[followerId].erase(it);
        return;
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