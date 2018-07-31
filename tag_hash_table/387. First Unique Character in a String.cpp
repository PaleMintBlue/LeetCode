class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty())
            return -1;
        vector<int> hash(26,0);
        for(const auto& ch:s)
        {
            if(hash[ch-'a']==0)
                hash[ch-'a']++;
            else if(hash[ch-'a']>0)
                hash[ch-'a'] *=-1;
        }
        for(int i = 0;i < s.size();i++)
        {
            if(hash[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};