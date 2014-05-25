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
    vector<TreeNode *> generateTrees(int n) {
  
        vector<TreeNode *> answer;
        
        if(n<=0){
        
            answer = getBST(1,0);
            
        }else{
        
            answer = getBST(1,n);
        }
        
        return answer;
        
    }
    
private:
    vector<TreeNode *> getBST(int begin,int end){
    
        
        
        vector<TreeNode *> answer;
        
        if(begin>end){
            
            
            answer.push_back(nullptr);
            
            return answer;
        } 
        
        for(int i=begin;i<=end;i++){
        
            vector<TreeNode *> left = getBST(begin,i-1);
            
            vector<TreeNode *> right = getBST(i+1,end);
            
            for(int m=0;m<left.size();m++){
            
                for(int n=0;n<right.size();n++){
                
                
                    TreeNode *temp = new TreeNode(i);
                    
                    temp->left = left[m];
                    
                    temp->right = right[n];
                    
                    answer.push_back(temp);
                    
                    
                }
            
            }
        
        }
        return answer;
        
    }
};