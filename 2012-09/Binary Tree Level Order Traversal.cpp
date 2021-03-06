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
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<vector<int>>  answer;
        
        if(!root){
            return answer;
        }
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        TreeNode *temp;
        
        int count = 1;
        
        vector<int> list;
        
        while(!Q.empty()){
            
            temp = Q.front();
            
            count--;
            
            Q.pop();
            
            list.push_back(temp->val);
            
            
            if (temp->left) {
                Q.push(temp->left);
            }
            if (temp->right) {
                Q.push(temp->right);
            }
            
            if(count==0){
                answer.push_back(list);
                list.clear();
                count = Q.size();
            }
            
            
        }
        return answer;
    }
};