class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())
            return;
        for(int i = 0,j = 0; i < nums.size(); i++)
        {
            if(nums[i])
                std::swap(nums[i],nums[j++]);
        }
    }
};