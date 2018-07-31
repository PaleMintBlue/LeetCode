/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
/*class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        std::unordered_map<int,Employee*> map;
        for(auto employee:employees)
        {
            map[employee->id] = employee;
        }
        return helper(map,id);
    }
    int helper(std::unordered_map<int,Employee*>& map,int id)
    {
        int val = 0;
        val += map[id]->importance;
        for(auto subId : map[id]->subordinates)
        {
            val += helper(map,subId);
        }
        return val;
    }
};*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        std::unordered_map<int,Employee*> map;
        int ret = 0;
        for(auto employee:employees)
        {
            map[employee->id] = employee;
        }
        std::queue<int> queue;
        queue.push(id);
        while(!queue.empty())
        {
            auto id = queue.front();
            queue.pop();
            ret += map[id]->importance;
            for(auto subId:map[id]->subordinates)
                queue.push(subId);
        }
        return ret;
    }
};