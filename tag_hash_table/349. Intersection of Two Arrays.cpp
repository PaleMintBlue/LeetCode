/*class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) {
            return intersection(nums2, nums1);
        }
        
        vector<int> res;
        unordered_set<int> s1, s2;
        int i;
        for (i = 0; i < n1; ++i) {
            s1.insert(nums1[i]);
        }
        for (i = 0; i < n2; ++i) {
            s2.insert(nums2[i]);
        }
        unordered_set<int>::const_iterator it;
        for (it = s1.begin(); it != s1.end(); ++it) {
            if (s2.find(*it) != s2.end()) {
                res.push_back(*it);
            }
        }
        return res;
    }
};*/
/*class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};*/
/*
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
    {
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        int i = 0, j = 0;
        std::set<int> set;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                set.insert(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j])
                i++;
            else 
                j++;
        }
        std::vector<int> ret;
        for(auto val:set)
        {
            ret.push_back(val);
        }
        return ret;
    }
};*/
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
    {
        std::sort(nums1.begin(),nums1.end());
        std::set<int> set;
        for(auto val:nums2)
            if(binarySearch(nums1,val))
                set.insert(val);
        std::vector<int> ret(set.size());
        std::copy(set.begin(),set.end(),ret.begin());
        return ret;
    }
private:
    bool binarySearch(std::vector<int>& num,int val)
    {
        int low = 0,high = num.size()-1;
        while(low<=high)
        {
            int mid = low + ((high-low)>>1);
            if(num[mid]==val)
                return true;
            else if(num[mid]>val)
                high = mid-1;
            else 
                low = mid+1;
        }
        return false;
    }
};