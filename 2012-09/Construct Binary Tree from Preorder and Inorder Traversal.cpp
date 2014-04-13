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

    int searchFatherNode(vector<int> &inorder,int val,int begin,int end){
        for(int i=begin;i<=end;i++)
            if(inorder[i]==val)
                return i;
        return -1;
    }
    
   TreeNode *buildBinaryTree(vector<int> &inorder,int inBegin,int inEnd,vector<int> &preorder,int preBegin,int preEnd){
    
    if(inBegin>inEnd||preBegin>preEnd)
        return NULL;
    
    
    TreeNode *root =new TreeNode(preorder[preBegin]);
    
    if(inBegin==inEnd){
        return root;
    }
    
    int temp = searchFatherNode(inorder, root->val,inBegin, inEnd);
    
    TreeNode *left;
    
    left = buildBinaryTree(inorder, inBegin, temp-1, preorder, preBegin+1, preBegin+temp-inBegin);
    
    root->left = left;
    
    TreeNode *right;
    
    right = buildBinaryTree(inorder, temp+1, inEnd, preorder, preBegin+temp-inBegin+1, preEnd);
    
    root->right = right;
    
    return root;
}
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        if(inorder.size()==0) return NULL;
        
        TreeNode *root;
        
        root = buildBinaryTree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
        
        return root;
    }

};