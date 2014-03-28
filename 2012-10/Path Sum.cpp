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
    bool hasPathSum(TreeNode *root, int sum) {
        
        if(root==NULL) return false;
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        while(!Q.empty()){
            
            TreeNode *temp;
            
            temp = Q.front();
            
            Q.pop();
            
            
            if(temp->left==NULL&&temp->right==NULL)
                if(temp->val==sum)
                    return true;
            
            
            if(temp->left!=NULL){
                
                TreeNode *left;
                
                left = temp->left;
                
                left->val = temp->val +left->val;
                
                Q.push(left);
            }
            
            
             if(temp->right!=NULL){
                
                TreeNode *right;
                
                right = temp->right;
                
                right->val = temp->val +right->val;
                
                Q.push(right);
            }
            
            
        }
        
        return false;
        
    }
};