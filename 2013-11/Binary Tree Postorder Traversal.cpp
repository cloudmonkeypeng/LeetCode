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
    vector<int> postorderTraversal(TreeNode *root) {
        
        vector<int> answer;
        
        postorderTraversals(root,answer);
        
        return answer;
    }
    
    void postorderTraversals(TreeNode *root,vector<int> &answer){
        
        if(!root) return;
        
        postorderTraversals(root->left,answer);
        postorderTraversals(root->right,answer);
        
        answer.push_back(root->val);
        
    }
    
    
};