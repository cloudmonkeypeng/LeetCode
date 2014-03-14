
//Maximum Depth of Binary Tree

//Given a binary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include <iostream>

using namespace std;


typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode,*BiTree;

//Create Binary Tree
int CreateBiTree(BiTree &T){
    int data;
    //Create the tree by preorder input
    //Input -1 means no leaf
    cout<<"input"<<endl;
    scanf("%d",&data);
    if(data == -1){
        T = NULL;
    }
    else{
        T = (BiTree)malloc(sizeof(TreeNode));
        T->val = data;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
    return 0;
}

// Answer
int maxDepth(TreeNode *root) {
    if(!root){
        return 0;
    }
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    if(left>right){
        return left+1;
    }else{
        return right+1;
    }
}

int main() {
    BiTree T = NULL;
    CreateBiTree(T);
    printf("%d\n",maxDepth(T));
    return 0;
}