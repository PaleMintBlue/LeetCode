class Solution {
public:
    int calPoints(vector<string>& ops) {
        if(ops.empty())
            return 0;
        int sum = 0, score = 0;
        std::vector<int> scores;
        for(const auto& op:ops)
        {
            if(op=="C")
            {
                sum -= scores.back();
                scores.pop_back();
                continue;
            }
            if(op=="D")
            {
                score = scores.back()*2;
                sum += score;
                scores.push_back(score);
            }else if(op=="+")
            {
                score = scores[scores.size()-1] + scores[scores.size()-2];
                sum += score;
                scores.push_back(score);
            }else
            {
                score = std::stoi(op);
                sum += score;
                scores.push_back(score);
            }
        }
        return sum;
    }
};