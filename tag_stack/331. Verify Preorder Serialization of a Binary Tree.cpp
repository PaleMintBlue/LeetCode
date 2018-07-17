class Solution {
public:
    /*bool isValidSerialization(string preorder) {
        std::stack<std::string> stack;
        std::vector<std::string> str_vec = split(preorder,',');
        for(int i = 0; i < str_vec.size(); i++)
        {
            while(!stack.empty()&&str_vec[i] == "#"&& str_vec[i]==stack.top()) 
            {
                stack.pop();
                if(stack.empty())
                    return false;
                stack.pop();
            }
            stack.push(str_vec[i]);
        }
        return stack.size() == 1 && stack.top() == "#";
    }*/
    bool isValidSerialization(string preorder)
    {
        /*
        all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
        all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
        */
        std::vector<std::string> str_vec = split(preorder,',');
        int diff = 1;
        for(const auto& str:str_vec)
        {
            if(--diff<0)
                return false;
            if(str!="#")
                diff += 2;
        }
        return diff == 0;
    }
private:
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};