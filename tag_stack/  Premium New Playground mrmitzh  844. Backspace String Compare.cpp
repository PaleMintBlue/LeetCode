class Solution {
public:
    bool backspaceCompare(string S, string T) {
        std::stack<char> stackS;
        std::stack<char> stackT;
        auto check = [](const std::string& str,std::stack<char>& stack)
        {
            for(const auto& ch:str)
            {
                if(ch!='#')
                    stack.push(ch);
                else if(!stack.empty())
                    stack.pop();
            }
        };
        check(S,stackS);
        check(T,stackT);
        return stackS == stackT;
    }
};