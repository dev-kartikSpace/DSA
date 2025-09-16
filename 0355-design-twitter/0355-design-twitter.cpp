class Twitter {
public:
    int timeStamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    // to store timestamp too to get most recent tweet
    Twitter() {
        // start from time = 0;
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // last value of twitter
        priority_queue<pair<int, int>> maxHeap; // for time and tweet

        // own tweet
        for (auto& tw : tweets[userId]) {
            maxHeap.push(tw);
        }

        // connections tweets
        for (auto& f : following[userId]) {
            for (auto& tw : tweets[f]) {
                maxHeap.push(tw);
            }
        }
        vector<int> res;
        int k = 10; // top 10 tweets
        while (!maxHeap.empty() && k--) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
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