class Solution {
public:
    bool isPalindrome(int x) {
        /*
        * 最后一位是0的话 由于第一位不可能是0 所以可以直接false
        */
        if(x<0 || (x!=0 && x%10 == 0))
            return false;
        int rev = 0;
        while(x>rev)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return (x==rev || x==rev/10);
    }
};