class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        std::unordered_map<int,int> map;
        int max = 0;
        for(const auto& brick:wall)
        {
            int sum = 0;
            for(auto i = 0;i < brick.size()-1;i++)
            {
                sum += brick[i];
                map[sum]++;
                max = std::max(max,map[sum]);
            }
        }
        return wall.size()-max;
    }
};