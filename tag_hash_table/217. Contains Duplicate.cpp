/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        std::unordered_set<int> mySet;
        for(const auto& num:nums)
        {
            auto found = mySet.find(num);
            if(found!=mySet.end())
                return true;
            else
                mySet.insert(num);
        }
        return false;
    }
};*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size();i++)
        {
            if(nums[i-1]==nums[i])
                return true;
        }
        return false;
    }
};