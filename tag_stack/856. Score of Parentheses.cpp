class Solution {
public:
    int scoreOfParentheses(string S) {
        std::stack<int> stack;
		for(const auto& ch: S)
		{
			if(ch=='(')
				stack.push(-1);
			else if(ch == ')')
			{
				int cur = 0;
				while(!stack.empty()&&stack.top()!=-1)
				{
					cur += stack.top();
					stack.pop();
				}
				stack.pop(); // pop -1
				stack.push(cur==0?1:2*cur);
			}
		}
		int sum = 0;
		while(!stack.empty())
		{
			sum += stack.top();
			stack.pop();
		}
		return sum;
    }
};