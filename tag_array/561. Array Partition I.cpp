class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        std::sort(nums.begin(),nums.end());
        long sum = 0;
        for(int i = 0;i<nums.size();i+=2)
            sum+= nums[i];
        return sum;
    }
};