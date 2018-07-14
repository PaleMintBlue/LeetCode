class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> map;
        for (auto val : hand) 
            map[val]++;
        for (auto it : map)
            if (map[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((map[it.first + i] -= map[it.first]) < 0)
                        return false;
        return true;
    }
};