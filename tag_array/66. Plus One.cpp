/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool needToAdd = true;
        for(int i = digits.size()-1;i>=0;i--)
        {
            if(needToAdd)
            {
                digits[i] += 1;
                if(digits[i]/10)
                {
                    needToAdd = true;
                    digits[i] %= 10;
                }else
                    needToAdd = false;
            }else
                break;
        }
        if(needToAdd)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;i--)
        {
            if(digits[i]==9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                break;
            }
        }
        if(digits[0]==0)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};