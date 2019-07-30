/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */
struct Post{
    int tweetId;
    long long time_stamp;
    Post* previous;
    Post(long long stamp, int tweet)
    {
        time_stamp = stamp;
        tweetId = tweet;
        previous = nullptr;
    };
    Post(long long stamp, int tweet, Post* last_post)
    {
        time_stamp = stamp;
        tweetId = tweet;
        previous = last_post;
    };
};

class MyCompare{
public:
    bool operator()(const Post *a, const Post *b) const
    {
        return a->time_stamp < b->time_stamp;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    map<int, Post*> posts;
    map<int, set<int>> followIDs;
    long long time_stamp;

    Twitter() {
        time_stamp = 0;    
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto it = posts.find(userId);        
        Post* new_post;
        if (it!=posts.end())
            new_post = new Post(time_stamp, tweetId, posts[userId]);
        else
            new_post = new Post(time_stamp, tweetId);
        posts[userId] = new_post;           
        time_stamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        if (followIDs.find(userId) == followIDs.end())
        {
            followIDs[userId] = set<int>();
            followIDs[userId].insert(userId);
        }
            
        priority_queue<Post*, vector<Post*>, MyCompare> q;
        for (auto it = followIDs[userId].begin(); it != followIDs[userId].end(); ++it)
            if (posts.find(*it) != posts.end())
                q.push(posts[*it]);
        int cnt = 0;
        Post* cur_post;
        while(cnt < 10 && !q.empty())
        {
            cur_post = q.top();
            q.pop();
            ans.push_back(cur_post->tweetId);
            if (cur_post->previous)
                q.push(cur_post->previous);
            cnt++;
        }
        return ans;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto it = followIDs.find(followerId);
        if (it != followIDs.end())
            followIDs[followerId].insert(followeeId);
        else
        {
            followIDs[followerId] = set<int>();
            followIDs[followerId].insert(followeeId);
            followIDs[followerId].insert(followerId);  // add him/herself
        }            
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId)
            return;  // cannot unfollow him/herself
        auto it = followIDs.find(followerId);
        if(it!=followIDs.end())
        {
            auto it = followIDs[followerId].find(followeeId);
            if (it != followIDs[followerId].end())
            {                
                followIDs[followerId].erase(it);
            }
        }
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

