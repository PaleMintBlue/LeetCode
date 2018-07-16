class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		std::vector<int> ret(temperatures.size(),0);
        std::stack<int> stack;
        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!stack.empty()&&temperatures[i]>temperatures[stack.top()])
            {
                ret[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);      
        }
		return ret;
    }
};