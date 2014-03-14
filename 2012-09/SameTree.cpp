
//Same Tree

//Given two binary trees, write a function to check if they are equal or not.
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.


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
bool isSameTree(TreeNode *p, TreeNode *q) {
    
    
    if(!p||!q){
        if(!p&&!q)
            return true;
        else
            return false;
    }
    
    if (p->val!=q->val)
        return false;
    
    bool left = isSameTree(p->left,q->left);
    
    bool right = isSameTree(p->right,q->right);
    
    return left&&right;
}


int main() {
    BiTree T = NULL;
    BiTree S = NULL;
    cout<<"input first"<<endl;
    CreateBiTree(T);
    cout<<"input another"<<endl;
    CreateBiTree(S);
    
    //data example  {}, {0}
    
    cout<<isSameTree(T,S)<<endl;
    return 0;
}