class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int number = 0;
        int sign = 1;
        std::stack<int> stack;
        for(const auto& c:s)
        {
            if(std::isdigit(c))
            {
                number = number*10 + (c-'0');
            }else if(c=='+')
            {
                result += sign*number;
                number = 0;
                sign = 1;
            }else if(c=='-')
            {
                result += sign*number;
                number = 0;
                sign = -1;
            }else if(c=='(')
            {
                stack.push(result);
                stack.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }else if(c==')')
            {
                result += sign*number;
                result *= stack.top();
                stack.pop();
                result += stack.top();
                stack.pop();
                number = 0;
            }
        }
        if(number!=0)
            result += number*sign;
        return result;
    }
};