/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
     if(k<=1) return head;
    
    ListNode *root =new ListNode(-1);
    
    root->next= head;
    
    ListNode *cur;
    
    head= root;
    
    while(head!=NULL&&head->next!=NULL){
        
        cur = head;
    
        for(int i=0;i<k&&cur!=NULL;i++)
            cur = cur ->next;
        
        if(cur==NULL)
            break;
        
        //旋转
        
        ListNode *pre;
        
        ListNode *temp;
        
        temp = head->next;
        
        pre = temp->next;
        
        for(int i=1;i<k;i++){
        
            
            temp->next = pre->next;
            
            pre->next = head->next;
            
            head->next = pre;
            
            pre = temp->next;
        }
        
        
        head = temp;

    }
    
    
    return root->next;
}

};