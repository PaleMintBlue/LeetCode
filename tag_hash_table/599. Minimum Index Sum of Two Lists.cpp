class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<std::string,int> map1;
        std::map<int,std::vector<std::string>> map3;
        for(int i = 0 ; i < list1.size(); i++)
        {
            map1[list1[i]] = i;
        }
        
        for(int i = 0; i < list2.size(); i++)
        {
            if(map1.count(list2[i]))
                map3[i+map1[list2[i]]].push_back(list2[i]);
        }
        auto begin = map3.begin();
        return (*begin).second;
    }
};