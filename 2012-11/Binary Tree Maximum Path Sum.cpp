class Solution {
public:
  int maxPathSum(TreeNode *root) {
    max_sum = INT_MIN;
    dfs(root);
    return max_sum;
  } 
private:
  int max_sum;

  int dfs(const TreeNode *root) {
    
    if (root == nullptr) return 0;
    
    int l = dfs(root->left);
    
    int r = dfs(root->right);
    
    int sum = root->val;
    
    if (l > 0) sum += l;
    if (r > 0) sum += r;
    
    max_sum = max(max_sum, sum);
    
    return max(r, l) > 0 ? max(r, l) + root->val : root->val;
  }
};


//自己写的
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        
        if(root==NULL)
            return ans;
        
        findMaxWay(root);
        
        return ans;
        
    }
private:
    
    int ans = INT_MIN;
    
    
    int findMaxWay(TreeNode *root){
    
    
        if(root==NULL)
            return 0;
        
        int left = findMaxWay(root->left);
        
        int right = findMaxWay(root->right);
        
        int temp = max(root->val,max(root->val+left+right,root->val+max(left,right)));
    
        ans = max(ans,temp);
        
        return max(root->val,max(root->val+left,root->val+right));
        
    }
    
    
};