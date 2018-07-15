class Solution {
public:
    bool isValid(string s) {
        std::stack<char> myStack;
        for(char c : s)
        {
            if(c=='(')
                myStack.push(')');
            else if(c=='{')
                myStack.push('}');
            else if(c=='[')
                myStack.push(']');
            else
            {
                if(myStack.empty()||myStack.top()!=c)
                    return false;
                if(!myStack.empty())
                   myStack.pop();
            }
        }
        return myStack.empty();
    }
};