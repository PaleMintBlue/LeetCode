class LRUCache {
public:
    LRUCache(int capacity) 
        :capacity(capacity)
    {
        
    }
    
    int get(int key) {
        if(map.find(key)==map.end())
            return -1;
        auto list_itr = map[key];
        list.splice(list.begin(),list,list_itr);
        return list_itr->second;
    }
    
    void put(int key, int value) {
        auto map_itr = map.find(key);
        if(map_itr!=map.end())
            list.erase(map_itr->second);
        list.push_front(std::make_pair(key,value));
        map[key] = list.begin();
        if(map.size()>capacity)
        {
            auto key = list.rbegin()->first;
            list.pop_back();
            map.erase(key);
        }
    }
private:
    int capacity;
    std::list<std::pair<int,int>> list;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */