class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(const char& ch:s)
            c ^= ch;
        for(const char& ch:t)
            c ^= ch;
        return c;
    }
};