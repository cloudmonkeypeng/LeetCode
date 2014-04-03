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

    void travsalBinaryTree(TreeNode *root,int sum,int nowSum,vector<int> &level,vector<vector<int>> &answer){
        
        if(root->left==NULL&&root->right==NULL&&sum==nowSum){
            answer.push_back(level);
            level.pop_back();
            return;
        }
        
        if(root->left!=NULL){
            level.push_back(root->left->val);
            travsalBinaryTree(root->left,sum,root->left->val+nowSum,level,answer);
        }
        
        if(root->right!=NULL){
            
            level.push_back(root->right->val);
            travsalBinaryTree(root->right,sum,root->right->val+nowSum,level,answer);
        }
        
        
        level.pop_back();
        
        return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        
        vector<vector<int>>  answer;
        
        if(root==NULL)  return answer;
        
        vector<int> level;
        
        level.push_back(root->val);
        
        travsalBinaryTree(root,sum,root->val,level,answer);
        
        return answer;
    }
};