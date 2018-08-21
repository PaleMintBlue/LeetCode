class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> set;
        while(n!=1)
        {
            int val = 0;
            while(n)
            {
                val += (n%10)*(n%10);
                n /= 10;
            }
            n = val;
            if(set.count(val))
                break;
            else
                set.insert(val);
        }
        return n==1;
    }
};