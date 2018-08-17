class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::vector<std::string> ret;
        std::unordered_map<std::string,int> map;
        for(const auto& word:words)
            map[word]++;
        auto comp = [](const std::pair<std::string,int>& a,const std::pair<std::string,int>& b)
        {
            return a.second > b.second || (a.second == b.second && a.first < b.first );
        };
        std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,decltype(comp)> q(comp);
        for(const auto& pair:map)
        {
            q.push(pair);
            if(q.size()>k)
                q.pop();
        }
        while(!q.empty())
        {
            ret.insert(ret.begin(),q.top().first);
            q.pop();
        }
        return ret;
    }
};