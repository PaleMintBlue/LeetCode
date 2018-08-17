class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        std::unordered_map<std::string,int> dict;
        std::vector<std::vector<int>> ret;
        
        for(int i = 0; i < words.size(); i++)
        {
            std::string key = words[i];
            std::reverse(key.begin(),key.end());
            dict[key] = i;
        }
        
        if(dict.find("") != dict.end())
        {
            for(int i = 0; i < words.size(); i++)
            {
                if(i==dict[""])
                    continue;
                if(isPalindrome(words[i]))
                    ret.push_back({dict[""],i});
            }
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size();j++)
            {
                std::string left = words[i].substr(0,j);
                std::string right = words[i].substr(j,words[i].size()-j);
                
                if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
                    ret.push_back({i,dict[left]});
                
                if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
                    ret.push_back({dict[right],i});
            }
        }
        
        return ret;
    }
private:
    bool isPalindrome(std::string str)
    {
        int i = 0;
        int j = str.size() -1 ;
        
        while(i < j)
        {
            if(str[i++]!=str[j--])
                return false;
        }
        
        return true;
    }
};