class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        	return "";
        std::string ret;
        for(int k = 0; k < strs[0].size();k++)
        {
        	int i = 1;

        	for(; i < strs.size() && strs[i].size() > k;i++)
        	{
        		if(strs[i][k]!=strs[0][k])
        			return ret;
        	}
        	if(i == strs.size())
        		ret += strs[0][k];
        }
        return ret;
    }
};
