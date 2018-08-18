/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string,int> map;
        std::vector<TreeNode*> ret;
        helper(root,map,ret);
        return ret;
    }
    std::string helper(TreeNode* root,std::unordered_map<std::string,int>& map,std::vector<TreeNode*>& ret)
    {
        if(!root)
            return "";
        auto str = to_string(root->val) + "L" + helper(root->left,map,ret) + "R" + helper(root->right,map,ret);
        if(map[str]==1)
            ret.push_back(root);
        map[str]++;
        return str;
    }*/
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        int type_id = 0;
        std::unordered_map<string,std::tuple<int,int,TreeNode*>> node_types; //(type_id,count,node)
        Traverse(root,type_id,node_types);
        std::vector<TreeNode*> result;
        for(auto& p:node_types)
        {
            if(std::get<1>(p.second)>1)
                result.push_back(std::get<2>(p.second));
        }
        return result;
    }
    int Traverse(TreeNode* root,int& type_id,std::unordered_map<std::string,std::tuple<int,int,TreeNode*>>& node_types)
    {
        if(!root)
            return -1;
        int left_type = Traverse(root->left,type_id,node_types);
        int right_type = Traverse(root->right,type_id,node_types);
        auto str = to_string(left_type) + "|"+to_string(root->val)+"|"+to_string(right_type);
        auto it = node_types.find(str);
        if(it!=node_types.end())
        {
            ++get<1>(it->second);
            return get<0>(it->second);
        }
        node_types[str] = std::make_tuple(type_id,1,root);
        return type_id++;
    }
};