class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto return_val = (map.find(val)==map.end());
        map[val].push_back(vec.size());
        vec.push_back({val,map[val].size()-1});
        return return_val;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end())
            return false;
        auto last = vec.back();
        map[last.first][last.second] = map[val].back();
        vec[map[val].back()] = last;
        map[val].pop_back();
        if(map[val].empty())
            map.erase(val);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand()%vec.size()].first;
    }
private:
    std::vector<std::pair<int,int>> vec;
    std::unordered_map<int,std::vector<int>> map;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */