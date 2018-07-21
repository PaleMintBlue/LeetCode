class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()!=speed.size())
            return 0;
        std::map<int,double> map;
        for(int i = 0;i < position.size();i++)
        {
            map[-position[i]] = static_cast<double>(target-position[i])/speed[i];
        }
        int res = 0;
        double cur = 0;
        for(auto pair:map)
        {
            if(pair.second>cur)
            {
                cur = pair.second;
                res++;
            }
        }
        return res;
    }
};