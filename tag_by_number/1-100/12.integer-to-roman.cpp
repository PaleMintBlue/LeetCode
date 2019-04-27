class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> values = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 
        };
        std::vector<std::string> numerals = 
        {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" 
        };
        
        std::string ret;
        for(int i = 0; i < values.size(); i++)
        {
            while(num >= values[i])
            {
                num -= values[i];
                ret += numerals[i];
            }
        }
        return ret;
    }
};