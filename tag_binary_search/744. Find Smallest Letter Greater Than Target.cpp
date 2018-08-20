class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto upper = std::upper_bound(letters.begin(),letters.end(),target);
        if(upper==letters.end())
            return letters[0];
        else
            return *upper;
    }
};