class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(const auto& str:dict)
        {
            map[str.size()].push_back(str);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(map.count(word.size())==0)
            return false;
        for(const auto& target:map[word.size()])
        {
            int cnt = 0,i;
            for(i=0; i < word.size();i++)
            {
                if(target[i]==word[i])
                    continue;
                if(target[i]!=word[i]&&cnt==1)
                    break;
                cnt++;
            }
            if(i==word.size()&&cnt==1)
                return true;
        }
        return false;
    }
private:
    std::unordered_map<int,std::vector<std::string>> map;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */