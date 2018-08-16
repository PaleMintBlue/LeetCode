class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> map;
        for(const auto& val:nums)
            map[val]++;
        std::map<int,std::unordered_set<int>> freq_map;
        for(const auto& pair:map)
        {
            if(freq_map[pair.second].count(pair.first)==0)
                freq_map[pair.second].insert(pair.first);
        }
        std::vector<int> ret;
        for(auto itr = freq_map.rbegin(); k>0 && itr != freq_map.rend();itr++)
        {
            ret.insert(ret.end(),itr->second.begin(),itr->second.end());
            k -= itr->second.size();
        }
        return ret;
    }
};