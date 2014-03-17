 vector<int> preorderTraversal(TreeNode *root) {
    
    vector<int> answer;
    preorderTraversals(root,answer);
    return answer;
}

void preorderTraversals(TreeNode *root,vector<int> &answer){
    
    if(!root) return;
    
    answer.push_back(root->val);
    preorderTraversals(root->left,answer);
    preorderTraversals(root->right,answer);
    
}