/*class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return std::max_element(A.begin(),A.end()) - A.begin();
    }
};*/
/*class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i = 1; i < A.size()-1;i++)
        {
            if(A[i]>A[i+1])
                return i;
        }
        return -1;
    }
};*/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int left = 0, right = A.size() -1 ;
        while(left < right)
        {
            int mid = left + ((right-left)>>1);
            if(A[mid]<A[mid+1])
                left = mid;
            else if(A[mid-1]>A[mid])
                right = mid;
            else
                return mid;
        }
        return -1;
    }
};
