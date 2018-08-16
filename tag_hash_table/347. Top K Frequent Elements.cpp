/*class Solution {
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
};*/
/*
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums,int k)
    {
        std::vector<int> ret;
        std::unordered_map<int,int> map;
        for(const auto& val:nums)
            map[val]++;
        for(const auto& pair:map)
            ret.push_back(pair.first);
        std::nth_element(ret.begin(),ret.begin()+k,ret.end(),[&map](int l,int r)->bool
                         {
                             return map[l] > map[r];
                         });
        ret.erase(ret.begin()+k,ret.end());
        return ret;
    }
};*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums,int k)
    {
        std::vector<int> ret;
        std::unordered_map<int,int> map;
        for(const auto& val:nums)
            map[val]++;
        for(const auto& pair:map)
            ret.push_back(pair.first);
        std::function<void (int,int)> quick_select = [&map,&ret,k,&quick_select] (int lo,int hi) 
        {
            int pivot_freq = map[ret[hi-1]];
            int idx = lo;
            
            for(int i = lo;i < hi; i++)
            {
                if(map[ret[i]] >= pivot_freq)
                    std::swap(ret[i],ret[idx++]);
            }
            
            if(idx==k)
                return;
            else if(idx < k )
                quick_select(idx,hi);
            else
                quick_select(lo,idx-1);
        };
        quick_select(0,ret.size());
        ret.erase(ret.begin()+k,ret.end());
        return ret;
    }
};