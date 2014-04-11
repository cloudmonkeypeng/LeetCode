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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        
        vector<vector<int>> answer;
        
        vector<int> level;
        
        if(root==NULL) {
            return answer;
        }
        
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        int num = 1;
        
        int row = 0;
        
        TreeNode *temp;
        
        while(!q.empty()){
            
            temp = q.front();
            
            q.pop();
           
            level.push_back(temp->val);
            
            num--;
            
                
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            
            if(temp->right!=NULL){
                q.push(temp->right);
            }
                
           
            
            if(num==0){
                
                
                num = q.size();
                
                if(row%2==0){
                    
                    answer.push_back(level);
                }else{
                    
                    vector<int> temp;
                    for(int i = level.size() - 1 ; i >= 0; --i) {
                        temp.push_back(level[i]);
                    }
                    answer.push_back(temp);
                    temp.clear();
                }
                
                level.clear();
                
                row++;
                
            }
            
        }
        
        return answer;
    }
};