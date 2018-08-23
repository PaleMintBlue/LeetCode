class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::multiset<int> set;
        for(auto num:nums)
        {
            if(set.size()<k)
                set.insert(num);
            else
            {
                auto itr = set.begin();
                if(num>*itr)
                {
                    set.erase(itr);
                    set.insert(num);
                }
            }
        }
        return *set.begin();
    }
};