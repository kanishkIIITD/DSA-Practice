class Twitter {
public:
    int time;
    vector<vector<pair<int, int>>> tweets;
    vector<unordered_set<int>> following;
    Twitter() {
        time = 0;
        tweets.resize(505);
        following.resize(505);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        int numOwnTweets = tweets[userId].size();
        for(int i = numOwnTweets-1; i >= max(0, numOwnTweets-10); i--)
            pq.push(tweets[userId][i]);
        for(auto& followeeId: following[userId]){
            int numFolloweeTweets = tweets[followeeId].size();
            for(int i = numFolloweeTweets-1; i >= max(0, numFolloweeTweets-10); i--)
                pq.push(tweets[followeeId][i]);
        }
        vector<int> result;
        int count = 0;
        while(!pq.empty() && count < 10){
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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