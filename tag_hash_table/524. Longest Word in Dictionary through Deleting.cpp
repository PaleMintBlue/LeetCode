class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        std::sort(d.begin(),d.end(),[](const std::string& a,const std::string& b)
                  {
                      return a.size() != b.size() ? a.size() > b.size() : a < b; 
                  });
        for(const auto& str:d)
        {
            int i = 0;
            for(auto c : s)
                if(i < str.size() && str[i]==c)
                    i++;
            if(i==str.size())
                return str;
        }
        return "";
    }
};