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
    
    bool Symmetric(TreeNode *right,TreeNode *left){
        
        if(!right&&!left) return true;
        
        if(!right||!left) return false;
        
        if(right->val!=left->val) return false;
        
        if(!Symmetric(right->right,left->left)) return false;
        
        if(!Symmetric(right->left,left->right)) return false;
        
        return true;
    }
    
    
    bool isSymmetric(TreeNode *root) {
        
        if(!root) return true;
        
        TreeNode *left;
        TreeNode *right;
        
        right = root->right;
        left = root->left;
        
        return Symmetric(right,left);
    }
};