class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {   
        std::vector<int> ret;
        for(int i = 0; i < asteroids.size(); i++)
        {
            bool should_push = true;
            while(!ret.empty()&&asteroids[i]<0&&ret.back()>0)
            {
                if(std::abs(asteroids[i])>std::abs(ret.back()))
                {
                    ret.pop_back();
                }else if(std::abs(asteroids[i])==std::abs(ret.back()))
                {
                    ret.pop_back();
                    should_push = false;
                    break;
                }else
                {
                    should_push = false;
                    break;
                }
            }
            if(should_push)
                ret.push_back(asteroids[i]);
        }
        return ret;
    }
};