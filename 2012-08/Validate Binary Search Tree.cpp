


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


void inOrder(vector<int> &level,TreeNode *root){

    if(root==NULL) return;
    
    inOrder(level,root->left);
    
    level.push_back(root->val);
    
    inOrder(level, root->right);

}

bool isValidBST(TreeNode *root) {

    if(root==NULL) return true;
    
    vector<int> level;
    
    inOrder(level, root);
    
    for(int i=0;i<level.size()-1;i++){
    
        if(level[i]>=level[i+1]){
            return false;
        }
    }
    
    return true;
}


int main() {
    BiTree T = NULL;
    CreateBiTree(T);
    
    cout<<isValidBST(T);
    return 0;
}

///////又tm被虐了

//很好的方法:如下



class Solution {
public:
    bool isValidBST(TreeNode *root) {
        
        return isValidBST(root,INT_MAX,INT_MIN);
        
    }
    
    bool isValidBST(TreeNode *root,int min,int max){
    
        if(root==NULL)
            return true;
        
        return root->val>min&&root->val<max&&isValidBST(root->left, min, root->val)&&isValidBST(root->right,root->val,max);
    
    }
};