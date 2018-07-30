class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::unordered_map<char,int> map;
        for(auto ch:J)
            map[ch]++;
        int count = 0;
        for(auto ch:S)
            if(map[ch])
                count++;
        return count;
    }
};