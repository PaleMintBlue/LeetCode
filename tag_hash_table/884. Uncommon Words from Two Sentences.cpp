class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        std::unordered_map<std::string,int> mapA;
        std::unordered_map<std::string,int> mapB;
        std::istringstream issA(A);
        std::istringstream issB(B);
        std::string temp;
        while(issA>>temp)
        {
            mapA[temp]++;
        }
        while(issB>>temp)
        {
            mapB[temp]++;
        }
        std::vector<std::string> ret;
        for(const auto& pair:mapA)
        {
            if(pair.second==1&&mapB.find(pair.first)==mapB.end())
                ret.push_back(pair.first);
        }
        for(const auto& pair:mapB)
        {
            if(pair.second==1&&mapA.find(pair.first)==mapA.end())
                ret.push_back(pair.first);
        }
        return ret;
    }
};