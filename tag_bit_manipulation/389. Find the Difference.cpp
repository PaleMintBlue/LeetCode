/*class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(const char& ch:s)
            c ^= ch;
        for(const char& ch:t)
            c ^= ch;
        return c;
    }
};*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char,int> map;
        for(auto ch:s)
            map[ch]++;
        for(auto ch:t)
            if(--map[ch]<0)
                return ch;
    }
};