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
    ListNode *rotateRight(ListNode *head, int k) {
        
        
        if(!head) return head;
        
        if(k==0) return head;
        
        int count=0;

        ListNode *begin;
        
        begin = head;
            
        while(begin!=NULL){
            count++;
            begin = begin->next;
        }
        
        
        k = k%count;
        
        ListNode *first;
        
        first = head;
        
        ListNode *second;
        
        second = head;
        
        if(k==0) return head;
        
        for(int i=0;i<k;i++)
            first = first->next;
            
        while(first->next!=NULL){
            first = first->next;
            second = second->next;
        }
        
        ListNode *root;
        
        root = second->next;
        
        second->next =NULL;
        
        first->next = head;
        
        return root;
    }
};