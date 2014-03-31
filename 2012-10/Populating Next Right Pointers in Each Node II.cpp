/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
         if(!root){
            //root->next = NULL;
            return;
        }
        
        queue<TreeLinkNode*> Q;
        
        Q.push(root);
        
        TreeLinkNode *temp;
        
        int count = 1;
        
        while(!Q.empty()){
            
            temp = Q.front();
            
            count--;
            
            Q.pop();
            
            if (temp->left) {
                Q.push(temp->left);
                }
                
            if (temp->right) {
                Q.push(temp->right);
            }
            
            if(count==0){
                temp->next = NULL;
                count = Q.size();
            }else{
                temp->next = Q.front();
            }
            
            
        }
        
    }
};