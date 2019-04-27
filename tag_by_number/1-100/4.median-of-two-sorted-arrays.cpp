class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
        	return findMedianSortedArrays(nums2,nums1);
        }
        int x = nums1.size();
        int y = nums2.size();

        int left = 0;
        int right = x;
        while(left <= right)
        {
        	int mid1 = left + (right - left)/2;
        	int mid2 = (x+y+1)/2 - mid1;

        	int maxLeftX = mid1 == 0?std::numeric_limits<int>::min():nums1[mid1-1];
        	int minRightX = mid1 == x?std::numeric_limits<int>::max():nums1[mid1];

        	int maxLeftY = mid2 == 0?std::numeric_limits<int>::min():nums2[mid2-1];
        	int minRightY = mid2 == y?std::numeric_limits<int>::max():nums2[mid2];

        	if(maxLeftX <= minRightY && maxLeftY <= minRightX)
        	{
        		if((x+y)%2 == 0)
        		{
        			return static_cast<double>(std::max(maxLeftX,maxLeftY) + std::min(minRightX,minRightY))/2;
        		}else
        		{
        			return static_cast<double>(std::max(maxLeftX,maxLeftY));
        		}
        	}else if(maxLeftX > minRightY)
        	{
        		right = mid1-1;
        	}else
        	{
        		left = mid1+1;
        	}
        }
        return -1;
    }
};
