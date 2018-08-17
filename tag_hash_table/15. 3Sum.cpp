class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
        std::vector<std::vector<int>> ret;
        std::sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++)
        {
            int target = -nums[i];
            int front = i+1;
            int end = nums.size()-1;
            while(front < end )
            {
                int val = nums[front] + nums[end];
                if(val < target)
                    front++;
                else if(val > target)
                    end--;
                else
                {
                    std::vector<int> triple(3);
                    triple[0] = nums[i];
                    triple[1] = nums[front];
                    triple[2] = nums[end];
                    ret.push_back(triple);
                    while(front < end && nums[front] == triple[1])
                        front++;
                    while(front < end && nums[end] == triple[2])
                        end--;
                }
            }
            while(i < nums.size()-1 && nums[i]==nums[i+1])
                i++;
        }
        return ret;
    }
};