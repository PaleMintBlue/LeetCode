/*class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> myMap{};
        std::vector<int> ret{};
        for(const auto& num:nums1)
            myMap[num]++;
        for(const auto& num:nums2)
        {
            auto found = myMap.find(num);
            if(found!=myMap.end()&&--found->second>=0)
            {
                ret.push_back(num);
            }
        }
        return ret;
    }
};*/
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1,vector<int>& nums2)
    {
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        int i = 0, j = 0;
        std::vector<int> ret;
        while(i < nums1.size()&& j < nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                ret.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return ret;
    }
};