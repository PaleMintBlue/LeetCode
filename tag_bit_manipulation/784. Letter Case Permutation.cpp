class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        std::vector<std::string> res;
        helper(S,0,res);
        return res;
    }
private:
    void helper(std::string& s,int i,std::vector<std::string>& res)
    {
        if(i==s.size())
        {
            res.push_back(s);
            return;
        }
        helper(s,i+1,res);
        if(std::isalpha(s[i]))
        {
            s[i] ^= (1<<5);
            helper(s,i+1,res);
        }
    }
};