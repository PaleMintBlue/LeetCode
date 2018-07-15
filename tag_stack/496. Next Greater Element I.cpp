class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        std::stack<int> stack;
        std::unordered_map<int,int> map;
        for(const auto& num : nums)
        {
            while(!stack.empty()&&stack.top()<num)
            {
                auto topVal = stack.top();
                stack.pop();
                map[topVal] = num;
            }
            stack.push(num);
        }
        std::vector<int> ret;
        for(const auto& num:findNums)
        {
            ret.push_back(map.count(num)?map[num]:-1);
        }
        return ret;
    }
};