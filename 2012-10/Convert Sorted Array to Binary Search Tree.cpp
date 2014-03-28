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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        
        if (num.size() == 0) return NULL;  
        
        int start =  0;
        int end = num.size() - 1;  
        
        if (start <= end)  
        {  
            if (start == end)  
            {  
                TreeNode *root = new TreeNode(num[start]);  
                return root;  
            }  
            int mid = (end - start) / 2;  
            vector<int> left(num.begin(), num.begin() + mid);  
            vector<int> right(num.begin() + mid + 1, num.end());  
            TreeNode *root = new TreeNode(num[mid]);  
            root->left = sortedArrayToBST(left);  
            root->right = sortedArrayToBST(right);  
            return root;  
        }  
        return NULL;  
        
    }
};