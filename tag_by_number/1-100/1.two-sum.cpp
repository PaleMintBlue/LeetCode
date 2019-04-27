class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        std::vector<int> ret;
        for(int i = 0; i < nums.size();i++)
        {
        	if(map.find(target-nums[i])!=map.end())
        	{
        		ret.push_back(map[target-nums[i]]);
        		ret.push_back(i);
        	}
        	map[nums[i]] = i;
        }
        return ret;
    }
};
