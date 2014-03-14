
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
#include <queue>

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

// Answer 1
int maxDepth(TreeNode *root) {

    if(!root) return 0;

    return 1+max(maxDepth(root->left),maxDepth(root->right));
}


//Answer 2  BFS in queue 
int maxDepth2(TreeNode *root){

    if(!root) return 0;
    
    int depth = 0;
    
    queue<TreeNode*> Q;
    
    Q.push(root);
    int count =1;
    
    TreeNode *temp;
    
    while (!Q.empty()) {
        
        temp = Q.front();
        
        Q.pop();
        
        count--;
        
        if (temp->left) {
            Q.push(temp->left);
        }
        
        if (temp->right) {
            Q.push(temp->right);
        }
        
        if (count==0) {
            depth++;
            count = Q.size();
        }
    }
    
    return depth;
}

int main() {
    BiTree T = NULL;
    CreateBiTree(T);
    printf("%d\n",maxDepth(T));
    return 0;
}