/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
};*/
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        std::unordered_map<int,int> map;
        for(auto val:nums)
            map[val]++;
        for(auto pair:map)
            if(pair.second==1)
                return pair.first;
        return -1;
    }
};