vector<int> inorderTraversal(TreeNode *root) {
   
   vector<int> answer;
   inorderTraversals(root,answer);
   return answer;

}

void inorderTraversals(TreeNode *root,vector<int> &answer){
    
    if(!root) return;
    
    inorderTraversals(root->left,answer);
    answer.push_back(root->val);
    inorderTraversals(root->right,answer);
}