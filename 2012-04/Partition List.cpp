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
    ListNode *partition(ListNode *head, int x) {
        
    //if(head==NULL||head->next==NULL) return head;
    
    ListNode *root = new ListNode(-1);
    
    root->next = head;
    
    ListNode *cur;
    
    ListNode *smallEnd;
    
    ListNode *bigPre;
    
    smallEnd = root;
    
    cur = head;
    
    bigPre  = root;
    
    while(cur!=NULL){
    
        if(cur->val<x){
            
            if(smallEnd==bigPre){
                
                smallEnd = bigPre =cur;
                cur = cur->next;
            }else{
            
            
            bigPre->next = cur->next;
            
            cur->next = smallEnd->next;
            
            smallEnd->next =cur;
            
            smallEnd = cur;
            
            cur = bigPre->next;
            }
        
        }else{
            
            bigPre = cur;
            
            cur = cur->next;
        
        }
        
    }
    
    
    
    return root->next;
}



};