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
    
    
    int Balanced(TreeNode *root){
        
        if(root==NULL) return 0;
        
        
        int left = Balanced(root->left);
        
        if(left==-1) return -1;
        
        int right = Balanced(root->right);
        
        if(right==-1) return -1;
    
        if(left-right>1||right-left>1) return -1;
        
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }
    }
 
public:
    bool isBalanced(TreeNode *root) {
      
      if(root==NULL) return true;
      
      int num = Balanced(root);
      
      if(num==-1) return false;
      
      return true;
      
    }
};