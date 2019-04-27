class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x)
        {
            int tail = x%10;
            if (std::abs(result) > INT_MAX/10 || (std::abs(result) == INT_MAX / 10 && tail > 7)) {
                return 0;
            }
            result = result*10 + tail;
            x /= 10;
        }
        return result;
    }
};