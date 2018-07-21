/*class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        return num ^ mask;
    }
};*/
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) 
            mask <<= 1;
        return ~mask & ~num;
    }
};