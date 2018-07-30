class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::unordered_set<int> set;
        for(auto val:candies)
            set.insert(val);
        return std::min(set.size(),candies.size()/2);
    }
};