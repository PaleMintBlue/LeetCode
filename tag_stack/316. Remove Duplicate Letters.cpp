class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::vector<int> cnt(26);
        int pos = 0;
        for(int i = 0; i < s.size();i++)
            cnt[s[i]-'a']++;
        for(int i = 0; i < s.size();i++)
        {
            if(s[i]<s[pos])
                pos = i;
            if(--cnt[s[i]-'a'] == 0)
                break;
        }
        if(!s.empty())
        {
            std::string str = s.substr(pos+1);
            str.erase(std::remove(str.begin(),str.end(),s[pos]),str.end());
            str= removeDuplicateLetters(str);
            return s[pos] + str;
        }
        return "";
    }
};