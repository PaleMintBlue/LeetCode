/*class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        return s==t;
    }
};
*/
class Solution
{
public:
    bool isAnagram(string s,string t)
    {
        if(s.size()!=t.size())
            return false;
        std::unordered_map<char,int> map;
        for(auto ch:s)
        {
            map[ch]++;
        }
        for(auto ch:t)
        {
            if(--map[ch]<0)
                return false;
        }
        return true;
    }
};