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
    TreeNode *s1,*s2,*pre;
    
    void preOrder(TreeNode *root)
    {
        if(!root)return ;
        
        
        preOrder(root->left);
        
        
        if(pre&& pre->val > root->val)
        {
            if(s1==NULL)s1=pre,s2=root;
            else s2=root;
        }
        pre=root;
        
        preOrder(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        if(!root)return ;
        s1=s2=pre=NULL;
        proOrder(root);
        swap(s1->val,s2->val);
    }
    
};