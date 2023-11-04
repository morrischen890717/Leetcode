class TweetCounts {
public:
    unordered_map<string, multiset<int>> m;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
        return;
    }

    int time2sec(string freq){
        if(freq == "minute")
            return 60;
        else if(freq == "hour")
            return 3600;
        return 86400;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        // using unordered_map and multiset
        int chunk = time2sec(freq);
        int num = (endTime - startTime + 1) / chunk + ((endTime - startTime + 1) % chunk ? 1 : 0);
        vector<int> ans(num, 0);
        set<int>::iterator it_start = m[tweetName].lower_bound(startTime), it_end = m[tweetName].upper_bound(endTime);
        int time = startTime, cnt = 0;
        while(it_start != it_end){
            ans[(*it_start - startTime) / chunk]++;
            it_start++;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */