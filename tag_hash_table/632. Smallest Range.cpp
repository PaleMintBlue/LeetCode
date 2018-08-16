class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using vi = std::vector<int>::iterator;
        auto comp = [](std::pair<vi,vi>& p1,std::pair<vi,vi>& p2)
        {
            return *p1.first > *p2.first;  
        };
        std::priority_queue<std::pair<vi,vi>,std::vector<std::pair<vi,vi>>,decltype(comp)> pq(comp);
        int lo = std::numeric_limits<int>::max();
        int hi = std::numeric_limits<int>::min();
        for(auto& row:nums)
        {
            lo = std::min(lo,row[0]);
            hi = std::max(hi,row[0]);
            pq.push({row.begin(),row.end()});
        }
        
        std::vector<int> ret{lo,hi};
        while(true)
        {
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if(p.first == p.second)
                break;
            pq.push(p);
            
            lo = *pq.top().first;
            hi = std::max(hi,*p.first);
            if(hi - lo < ret[1] - ret[0])
                ret = {lo,hi};
        }
        return ret;
    }
};