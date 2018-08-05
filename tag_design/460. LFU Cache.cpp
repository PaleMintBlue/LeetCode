class LFUCache {
public:
    LFUCache(int capacity) 
        :capacity(capacity)
    {
        
    }
    
    int get(int key) {
        if(minFreq==-1)
            return -1;
        if(map.find(key)==map.end())
            return -1;
        freq_map[map[key].second].erase(iter_map[key]);
        map[key].second++;
        freq_map[map[key].second].push_back(key);
        iter_map[key] = --freq_map[map[key].second].end();
        if(freq_map[minFreq].size()==0) //get operator may make the old list empty, therefore we should increase the minFreq by one
            minFreq++;
        return map[key].first;
        
    }
    
    void put(int key, int value) {
        if(capacity<=0)
            return;
        if(get(key)!=-1)
        {
            map[key].first = value;
            return;
        }
        if(map.size()>=capacity)
        {
            map.erase(freq_map[minFreq].front());
            iter_map.erase(freq_map[minFreq].front());
            freq_map[minFreq].pop_front();
        }
        map[key] = {value,1};
        freq_map[1].push_back(key);
        iter_map[key] = --freq_map[1].end();
        minFreq = 1;
    }
private:
    int capacity;
    int minFreq = -1;
    std::unordered_map<int,std::pair<int,int>> map; // key to {value,freq}
    std::unordered_map<int,std::list<int>> freq_map; // freq to list of key
    std::unordered_map<int,std::list<int>::iterator> iter_map; // key to list iterator
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */