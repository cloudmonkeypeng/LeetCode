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
    ListNode *swapPairs(ListNode *head) {
        
        ListNode *root;
        ListNode *temp;
        ListNode *previous;
        
        if(!head||!(head->next)) return head;
        
        //previous->next = head;
        
        root = head->next;
        
        temp = head->next->next;
        head->next->next = head;
        head->next = temp;
        previous = head;
        head = temp;
        
        while(head&&(head->next)){
            previous->next = head->next;
            temp = head->next->next;
            previous->next->next = head;
            head->next = temp;
            
            previous = head;
            head =temp;
        }
        
        return root;
        
    }
};


//新写的解法

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *root = new ListNode(-1);
        
        root->next = head;
        
        ListNode *prev,*cur,*next;
        
        prev = root;
        
        cur = head;
        
        next = head->next;
        
        while(cur!=NULL&&next!=NULL){
        
            prev->next = next;
            
            cur->next = next->next;
            
            next->next = cur;
            
            prev =cur;
            
            cur = cur->next;
            
            if(cur!=NULL)
                next = cur->next;
            else
                break;
        }
        
        ListNode *temp = root->next;
        
        delete root;
        
        root = NULL;
        
        return temp;
        
    }
};