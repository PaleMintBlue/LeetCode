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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return nullptr;
        if(inorder.size()<1)
            return nullptr;
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder,int inStart,int inEnd,
                       vector<int>& postorder,int postStart,int postEnd)
    {
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);
        root->left = root->right = nullptr;
        if(inStart==inEnd)
        {
            if(postStart==postEnd&&inorder[inStart]==postorder[postStart])
                return root;
            else
                return nullptr;
        }
        int mid = inStart;
        while(mid!=inEnd)
        {
            if(inorder[mid]==rootValue)
                break;
            mid++;
        }
        if(mid==inEnd&&inorder[mid]!=rootValue)
            return nullptr;
        int leftLength = mid - inStart;
        int rightLength = inEnd - mid;
        if(leftLength>0)
            root->left = buildTree(inorder,inStart,mid-1,
                                  postorder,postStart,postEnd-rightLength-1);
        if(rightLength>0)
            root->right = buildTree(inorder,mid+1,inEnd,
                                   postorder,postStart+leftLength,postEnd-1);
        return root;
    }
};