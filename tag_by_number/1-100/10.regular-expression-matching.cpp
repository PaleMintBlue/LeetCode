class Solution {
public:
    bool isMatch(string text, string pattern) {
        std::vector<std::vector<bool>> dp(text.size()+1,std::vector<bool>(pattern.size()+1));
        dp[0][0] = true;
        
        for(int i = 2; i < dp[0].size(); i++)
        {
            if(pattern[i-1] == '*')
            {
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for(int i = 1; i < dp.size();i++)
        {
            for(int j = 1; j < dp[i].size();j++)
            {
                if(pattern[j-1] == '.' || text[i-1] == pattern[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }else if(pattern[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2]; // zero occurance
                    if(pattern[j-2] == '.' || pattern[j-2] == text[i-1])
                    {
                        // match 1 to any occurance
                        dp[i][j] = dp[i][j] | dp[i-1][j];
                    }
                }else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[text.size()][pattern.size()];
    }
};