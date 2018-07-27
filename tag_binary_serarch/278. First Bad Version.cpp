// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            int mid = left + ((right-left)>>1);
            if(isBadVersion(mid+1))
                right = mid;
            else
                left = mid+1;
        }
        return right+1;
    }
};*/
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left<right)
        {
            int mid = left + ((right-left)>>1);
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid+1;
        }
        return right;
    }
};