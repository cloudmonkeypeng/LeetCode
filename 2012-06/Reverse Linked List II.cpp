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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *reverseBetween(ListNode *head, int m, int n) {
    
    if(head==NULL||m>=n) return head;
    
    ListNode *root = new ListNode(-1);
    
    root->next = head;
    
    head = root;
    
    for(int i=1;i<m;i++)
        head = head->next;
    
    ListNode *post;
    
    post = head->next;
    
    
    ListNode *pre;
    
    pre = post->next;
    
    for(int i=0;i<n-m;i++){
        
        post->next = pre->next;
        
        pre->next = head->next;
        
        head->next = pre;
        
        pre = post->next;
    }
    
    return root->next;
}



int main(){
    
    cout<<"输入总共多少个节点："<<endl;
    
    int length;
    
    cin>>length;
    
    int tempNum;
    
    ListNode *cur = new ListNode(-1);
    
    ListNode *root;
    
    root = cur;
    
    for(int i=0;i<length;i++){
        
        cin>>tempNum;
        ListNode *temp =new ListNode(tempNum);
        cur->next = temp;
        cur = temp;
    }
    
    cur = root->next;
    
    cout<<"位置从m到n"<<endl;
    
    int m,n;
    
    cin>>m>>n;
    
    cur = reverseBetween(cur,m,n);
    
    while(cur!=NULL){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    
    return 0;
}