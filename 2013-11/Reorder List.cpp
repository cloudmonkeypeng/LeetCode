ListNode *reserve(ListNode *head){

    if(head==NULL||head->next==NULL) return head;
    
    ListNode *root = new ListNode(-1);
    
    root->next = head;
    
    ListNode *pre;
    
    ListNode *back;
    
    back = root->next;
    
    pre = back->next;
    
    while(pre!=NULL){
    
        back->next = pre->next;
        
        pre->next = root->next;
        
        root->next =pre;
        
        pre = back->next;
    }
    
    return root->next;
}


void reorderList(ListNode *head) {
    
    ListNode *root = new ListNode(-1);
    
    root->next = head;
    
    ListNode *fast,*slow;
    
    fast = slow = root;
    
    while(fast!=NULL&&fast->next!=NULL){
        
        slow = slow->next;
        
        fast = fast->next->next;
    }
    
    
    fast = slow->next;
    
    slow->next =NULL;  //彻底断开 很重要！
    
    slow = head;
    
    fast  = reserve(fast);
    
    while(fast!=NULL){
    
        ListNode *temp;
        
        temp = fast->next;
        
        fast->next = slow->next;
        
        slow->next = fast;
        
        slow = fast->next;
        
        fast = temp;
    }
    

}
