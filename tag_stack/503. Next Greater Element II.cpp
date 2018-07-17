class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> ret(nums.size(),-1);
        std::stack<int> stack;
        for(int i = 0; i < 2*nums.size();i++)
        {
            int num = nums[i%nums.size()];
            while(!stack.empty()&&nums[stack.top()]<num)
            {
                ret[stack.top()] = num;
                stack.pop();
            }
            if(i<nums.size())
                stack.push(i);
        }
        return ret;
    }
};