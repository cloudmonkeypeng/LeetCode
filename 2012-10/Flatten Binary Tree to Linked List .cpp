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

   
    
    void flatten(TreeNode *root) {
        
        if(root==NULL)
            return;  
        
        flatten(root->left);  
        
        flatten(root->right);  
        
        TreeNode *p=root;  
        
        if(p->left==NULL){
            return;
        }else{ 
            p=p->left;
        }  
        
        while(p->right!=NULL)
            p=p->right;  
        
        p->right=root->right;  
        
        root->right=root->left;          
        
        root->left=NULL;  
    }
};