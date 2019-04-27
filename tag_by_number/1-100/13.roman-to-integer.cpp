class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (dict.find(s.substr(i, 2)) != dict.end()) {
                num += dict[s.substr(i++, 2)];
            } else {
                num += dict[s.substr(i, 1)];
            }
        }
        return num;
    }
private:
    unordered_map<string, int> dict = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
};