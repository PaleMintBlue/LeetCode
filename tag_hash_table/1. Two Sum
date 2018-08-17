class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> myMap;
        for(int i = 0;i<nums.size();i++)
        {
            int toFind = target - nums[i];
            auto it = myMap.find(toFind);
            if(it!=myMap.end())
            {
                ret.push_back(it->second);
                ret.push_back(i);
                return ret;
            }
            myMap.insert(std::pair<int,int>(nums[i],i));
        }
        return ret;
    }
};