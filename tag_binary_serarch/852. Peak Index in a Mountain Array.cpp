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
/*
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
};*/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int left = 0,right = A.size() - 1;
        int x1 = gold1(left,right);
        int x2 = gold2(left,right);
        while(x1<x2)
        {
        	if(A[x1]<A[x2])
        	{
        		left = x1;
        		x1 = x2;
        		x2 = gold1(x1,right);
        	}else 
        	{
        		right = x2;
        		x2 = x1;
        		x1 = gold2(left,x2);
        	}
        }
        return x1;
    }
private:
	int gold1(int left,int right)
	{
		return left + static_cast<int>(round((right-left)*0.382));
	}
	int gold2(int left,int right)
	{
		return left + static_cast<int>(round((right-left)*0.618));
	}
};

