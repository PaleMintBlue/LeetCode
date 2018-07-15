/*class Solution {
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
};*/

class Solution
{
public:
    bool backspaceCompare(string S, string T) {
        for (int i = S.length() - 1, j = T.length() -1; ; i--, j--)
        {
            for(int b = 0; i >= 0 && (b || S[i] == '#'); i--)
                b += S[i] == '#' ? 1 : -1;
            for(int b = 0; j >= 0 && (b || T[j] == '#'); j--)
                b += T[j] == '#' ? 1 : -1;
            if(i<0||j<0||S[i]!=T[j]) // S[i] != T[j] exist for i>=0 and j>=0 with some word is not the same so we return false
                return i == -1 && j == -1;
        }
    }
};