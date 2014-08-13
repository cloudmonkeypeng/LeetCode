/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        
        if(root==NULL) return 0;
        
        if(root->left==NULL&&root->right==NULL)
            return 1;
        
        int l = INT_MAX;
        
        if(root->left!=NULL)
            l = minDepth(root->left);
            
        int r = INT_MAX;
        
        if(root->right!=NULL)
            r = minDepth(root->right);
        
        return min(r,l)+1;
    }
};