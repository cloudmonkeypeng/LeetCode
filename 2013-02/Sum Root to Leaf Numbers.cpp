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

    void getPath(TreeNode *root,vector<int> &answer,int sum){
        
        if(root==NULL) return;
        
        sum = sum*10+root->val;
        
        if(root->left==NULL&&root->right==NULL){
            
            answer.push_back(sum);
            return;
        }
        
        getPath(root->left,answer,sum);
        
        getPath(root->right,answer,sum);
        
    }
    
    int sumNumbers(TreeNode *root) {
        
        
        if(root==NULL) return NULL;
        
        vector<int> answer;
        
        getPath(root,answer,0);
        
        int sum =0;
        
        for(int i=0;i<answer.size();i++)
            sum = sum +answer[i];
            
        return sum;
        
    }
};