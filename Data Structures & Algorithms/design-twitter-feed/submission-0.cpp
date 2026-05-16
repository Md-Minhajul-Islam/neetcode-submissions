class Twitter {

public:
    int timeStamp;
    vector<vector<int>> followeeMap;
    vector<deque<pair<int, int>>> tweets;
    
    Twitter() {
        timeStamp = 0;
        followeeMap.resize(105, vector<int>(105));
        tweets.resize(105);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timeStamp, tweetId});
        if(tweets[userId].size() > 10) tweets[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> followeeTweets;
        for(int i = 0; i < 105; i++)
        {
            if(followeeMap[userId][i] || userId == i)
            {
                int sz = tweets[i].size();
                while(sz--)
                {
                    auto [t, ti] = tweets[i].front();
                    tweets[i].pop_front();
                    followeeTweets.push_back({t, ti});
                    tweets[i].push_back({t, ti});
                }
            }
        }
        sort(followeeTweets.rbegin(), followeeTweets.rend());
        vector<int> tweetsId;
        for(int i = 0; i < followeeTweets.size() && i < 10; i++)
        {
            tweetsId.push_back(followeeTweets[i].second);
        }
        return tweetsId;
    }
    
    void follow(int followerId, int followeeId) {
        followeeMap[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followeeMap[followerId][followeeId] = 0;
    }
};
