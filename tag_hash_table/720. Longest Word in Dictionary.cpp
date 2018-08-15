class Solution {
public:
    string longestWord(vector<string>& words) {
        std::sort(words.begin(),words.end());
        std::unordered_set<std::string> built;
        std::string res;
        for(const auto& word:words)
        {
            if(word.size()==1||built.count(word.substr(0,word.size()-1)))
            {
                res = word.size() > res.size() ? word : res;
                built.insert(word);
            }
        }
        return res;
    }
};