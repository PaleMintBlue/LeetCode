class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(key>=set.size())
            set.resize(key+1);
        set[key] = 1;
    }
    
    void remove(int key) {
        if(key>=set.size())
            return;
        set[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(key>=set.size())
            return false;
        return set[key] == 1;
    }
private:
    std::vector<int> set;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */