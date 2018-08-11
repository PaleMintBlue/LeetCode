class Twitter {
    struct Tweet
    {
        int time;
        int id;
        Tweet(int time,int id)
            :time(time),id(id)
        {}
    };
    int time;
    std::unordered_map<int,std::vector<Tweet>> tweets;
    std::unordered_map<int,std::unordered_set<int>> following;
public:
    /** Initialize your data structure here. */
    Twitter()
        :time(0)
    {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].emplace_back(time++,tweetId);    
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        std::vector<std::pair<Tweet*,Tweet*>> h;
        
        for(auto& u:following[userId])
        {
            auto& t = tweets[u];
            if(t.size()>0)
                h.emplace_back(t.data(),t.data()+t.size()-1);
        }
        auto& t = tweets[userId]; // self
        if(t.size()>0)
            h.emplace_back(t.data(),t.data()+t.size()-1);
        
        auto f = [](const std::pair<Tweet*,Tweet*>& x, const std::pair<Tweet*,Tweet*>& y)
        {
            return x.second->time < y.second->time;  
        };
        std::make_heap(h.begin(),h.end(),f);
        
        constexpr int n = 10;
        std::vector<int> ret;
        ret.reserve(n);
        for(int i = 0; (i<n)&&!h.empty();i++)
        {
            std::pop_heap(h.begin(),h.end(),f);
            
            auto& hb = h.back();
            ret.push_back(hb.second->id);
            if(hb.first==hb.second--)
                h.pop_back();
            else
                std::push_heap(h.begin(),h.end(),f);
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        following[followerId].erase(followeeId);    
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */