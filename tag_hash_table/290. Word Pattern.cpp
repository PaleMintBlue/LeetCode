class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::unordered_map<char,int> p2i;
        std::unordered_map<std::string,int> w2i;
        std::istringstream in(str);
        int i = 0, n = pattern.size();
        for(string word; in >> word ; i++)
        {
            if(i==n||p2i[pattern[i]]!=w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i+1;
        }
        return i==n;
    }
};