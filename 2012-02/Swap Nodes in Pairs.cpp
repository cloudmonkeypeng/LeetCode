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