/*class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		std::unordered_map<int,int> map;
		for(const auto& num:nums)
		{
			if(++map[num]>nums.size()/2)
				return num;
		}
		return -1;
	}	
};*/

/*class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		std::sort(nums.begin(),nums.end());
		return nums[nums.size()/2];
	}	
};*/
/*
class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		std::nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
		return nums[nums.size()/2];
	}	
};*/
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(nullptr)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }
};*/
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};*/
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
private:
    int helper(std::vector<int>& nums,int left,int right)
    {
        if(left==right)
            return nums[left];
        int mid = left + ((right-left)>>1);
        int leftMost = helper(nums,left,mid);
        int rightMost = helper(nums,mid+1,right);
        if(leftMost==rightMost)
            return leftMost;
        return std::count(nums.begin()+left,nums.begin()+right+1,leftMost) > std::count(nums.begin()+left,nums.begin()+right+1,rightMost) ? leftMost: rightMost;
    }
};*/
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int major = 0, n = nums.size();
        for(int i = 0, mask = 1; i < 32; i++,mask <<= 1)
        {
            int bitCounts = 0;
            for(int j = 0; j < n; j++)
            {
                if(nums[j]&mask)
                    bitCounts++;
                if(bitCounts > n / 2)
                {
                    major |= mask;
                    break;
                }
            }
        }
        return major;
    }
};