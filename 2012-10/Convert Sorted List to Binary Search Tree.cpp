class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    
        return sortedListToBST(head,listLength(head));
        
    }
    
    TreeNode *sortedListToBST(ListNode *head,int length){
    
        if(length ==0) return  nullptr;
        
        if(length==1) {
            
            TreeNode *temp = new TreeNode(head->val);
            
            return temp;
        }
        
        ListNode *tempList = nthNode(head,length/2+1);
        
        TreeNode *tempTree = new TreeNode(tempList->val);
        
        tempTree->left =sortedListToBST(head,length/2);
        
        tempTree->right = sortedListToBST(tempList->next,(length-1)/2);
        
        return tempTree;
    }
    
    ListNode *nthNode(ListNode *head,int length){
    
        while(--length)
            head = head->next;
        return head;
        
    }
    
    int listLength(ListNode *head){
        
        int n=0;
        
        while(head){
            n++;
            head = head->next;
        }
    
        return n;
    }
};


