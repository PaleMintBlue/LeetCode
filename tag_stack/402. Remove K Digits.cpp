class Solution {
public:
    string removeKdigits(string num, int k) {
        int digits = num.size() - k;
        int top = 0;
        std::vector<char> stack(num.size());
        for(const auto& c:num)
        {
            while(top>0&&stack[top-1]>c&&k>0)
            {
                top--;
                k--;
            }
            stack[top++] = c;
        }
        int idx = 0;
        while (idx < digits && stack[idx] == '0') 
            idx++;
        return idx == digits? "0": std::string(stack.begin()+idx,stack.begin() + digits);
    }
};