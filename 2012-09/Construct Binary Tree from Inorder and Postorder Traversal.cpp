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

TreeNode *buildBinaryTree(vector<int> &inorder,int inBegin,int inEnd,vector<int> &postorder,int postBegin,int postEnd){
    
    if(inBegin>inEnd||postBegin>postEnd)
        return NULL;
    
    
    TreeNode *root =new TreeNode(postorder[postEnd]);
    
    if(inBegin==inEnd){
        return root;
    }
    
    int temp = searchFatherNode(inorder, root->val,inBegin, inEnd);
    
    TreeNode *left;
    
    left = buildBinaryTree(inorder, inBegin, temp-1, postorder, postBegin, postBegin+temp-1-inBegin);
    
    root->left = left;
    
    TreeNode *right;
    
    right = buildBinaryTree(inorder, temp+1, inEnd, postorder, postBegin+temp-inBegin, postEnd-1);
    
    root->right = right;
    
    
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    
    if(inorder.size()==0) return NULL;
    
    TreeNode *root;
    
    root = buildBinaryTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    
    return root;
}

};