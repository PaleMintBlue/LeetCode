class Solution {
public:
    string decodeString(string s) {
        std::string res;
        std::stack<int> countStack;
        std::stack<std::string> resStack;
        for(int i = 0; i < s.size(); )
        {
            if(std::isdigit(s[i])) 
            {
                int count = 0;
                while(std::isdigit(s[i]))
                {
                    count = count*10 + s[i] - '0';
                    i++;
                }
                countStack.push(count);
            }else if(s[i]=='[')
            {
                resStack.push(res);
                res.clear();
                i++;
            }else if(s[i]==']')
            {
                int repeatTimes = countStack.top();
                countStack.pop();
                std::string temp = resStack.top();
                resStack.pop();
                for(int i = 0; i< repeatTimes; i++)
                    temp += res;
                res = temp;
                i++;
            }else
                res += s[i++];
        }
        return res;
    }
};