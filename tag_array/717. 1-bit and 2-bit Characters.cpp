class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int oneBits = 0;
        int i;
        for(i = 0;i < bits.size()-1;)
        {
            if(bits[i])
                i+=2;
            else
                i++;
        }
        return i==bits.size()-1?true:false;
    }
};