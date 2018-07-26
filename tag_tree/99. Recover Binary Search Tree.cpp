/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    void recoverTree(TreeNode* root) {
  		if(!root)
  			return;      
  		std::vector<TreeNode*> node_vec;
  		std::vector<int> value_vec;
  		inorder(root,node_vec,value_vec);
  		std::sort(value_vec.begin(),value_vec.end());
  		for(int i = 0; i < node_vec.size(); i++)
  		{
  			node_vec[i]->val = value_vec[i];
  		} 
    }
    void inorder(TreeNode* root,std::vector<TreeNode*>& node_vec,std::vector<int>& value_vec)
    {
    	if(!root)
    		return;
    	inorder(root->left,node_vec,value_vec);
    	node_vec.push_back(root);
    	value_vec.push_back(root->val);
    	inorder(root->right,node_vec,value_vec);
    }
};*/
/*class Solution {
public:
    void recoverTree(TreeNode* root) {
  		if(!root)
  			return;      
  		TreeNode* preNode = nullptr;
  		TreeNode* firstNode = nullptr;
  		TreeNode* secondNode = nullptr;
  		inorder(root,preNode,firstNode,secondNode);
  		if(firstNode&&secondNode)
  			std::swap(firstNode->val,secondNode->val);
    }
    void inorder(TreeNode* root,TreeNode*& preNode,TreeNode*& firstNode,TreeNode*& secondNode)
    {
    	if(!root)
    		return;
    	inorder(root->left,preNode,firstNode,secondNode);
    	if(!preNode)
    		preNode = root;
    	else
    	{
    		if(preNode->val>root->val)
    		{
    			if(!firstNode)
    				firstNode = preNode;
    			secondNode = root;
    		}
    		preNode = root;
    	}
    	inorder(root->right,preNode,firstNode,secondNode);
    }
};*/
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
    Solution()
    {
        prevElement = &prev;
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(firstElement->val,secondElement->val);
    }
    void traverse(TreeNode* root)
    {
        if(!root)
            return;
        traverse(root->left);
        if(!firstElement&&prevElement->val >= root->val)
            firstElement = prevElement;
        if(firstElement&&prevElement->val>=root->val)
            secondElement = root;
        prevElement = root;
        traverse(root->right);
    }
private:
    TreeNode* firstElement = nullptr;
    TreeNode* secondElement = nullptr;
    TreeNode* prevElement = nullptr;
    TreeNode prev = TreeNode(std::numeric_limits<int>::min());
};