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
        
        if((root->left==NULL)&&(root->right==NULL)) return 1;
        
        
        int left = 0;
        
        int right = 0;
        
        int height;
        
        left = minDepth(root->left);
        
        right = minDepth(root->right);
        
       
        if(right==0) return left +1;
        
        if(left==0) return right+1;
        
        
        if(left>right){
            return  right+1;
        }else{
            return left+1;
        }
    }
};