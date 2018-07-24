class Solution
{
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) 
	{
    	if(!root1&&!root2)
    		return true;
    	if(!root1||!root2)
    		return false;
    	std::vector<int> left1;
    	std::vector<int> left2;
    	getLeaf(root1,left1);
    	getLeaf(root2,left2);
		if(left1.size()!=left2.size())
			return false;    	
    	for(int i = 0; i < left1.size(); i++)
    	{
    		if(left1[i]!=left2[i])
    			return false;
    	}    
    	return true;
    }
    void getLeaf(TreeNode* root,std::vector<int>& vec)
    {
    	if(!root)
    		return;
    	std::stack<TreeNode*> stack;
    	stack.push(root);
    	while(!stack.empty())
    	{
    		auto node = stack.top();
    		stack.pop();
    		if(!node->left&&!node->right)
    		{
    			vec.push_back(node->val);
    		}
    		if(node->right)
    		{
    			stack.push(node->right);
    		}
    		if(node->left)
    		{
    			stack.push(node->left);
    		}
    	}
    }
};
