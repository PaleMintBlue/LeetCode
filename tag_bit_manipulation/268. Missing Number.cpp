/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::set<int> mySet(nums.begin(),nums.end());
        int ret = 0;
        for(auto itr = mySet.begin();itr!=mySet.end();itr++)
        {
            if(ret==*itr)
                ret++;
            else
                break;
        }
        return ret;
    }
};*/
/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int ret = 0;
        for(;i < nums.size();i++)
            ret = ret ^ i ^ nums[i];
        return ret^i;
    }
};*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + ((right-left)>>1);
            if(nums[mid]>mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};