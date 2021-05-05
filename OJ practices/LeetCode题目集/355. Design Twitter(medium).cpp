/*
 * @Author: SourDumplings
 * @Date: 2021-05-05 11:44:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/design-twitter/
 */

class Twitter
{
private:
    static const int maxUserNum = 600;
    vector<int> tweets;
    vector<int> userTweetIdxes[maxUserNum]; // 存储用户发的推特的存储索引序号
    unordered_set<int> userFollows[maxUserNum];
public:
    /** Initialize your data structure here. */
    Twitter()
    {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        userTweetIdxes[userId].push_back(tweets.size());
        tweets.push_back(tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        unordered_set<int> users = userFollows[userId];
        users.insert(userId);
        priority_queue<int> pQ;
        for (int userId : users)
        {
            const vector<int> &tweetIdxes = userTweetIdxes[userId];
            for (int tweetIdx : tweetIdxes)
            {
                pQ.push(tweetIdx);
            }
        }
        vector<int> res;
        for (int i = 0; !pQ.empty() && i < 10; ++i)
        {
            res.push_back(tweets[pQ.top()]);
            pQ.pop();
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        userFollows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        userFollows[followerId].erase(followeeId);
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
