//没有检验n过长

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        
        
        if(head==NULL) return head;
        
        ListNode *root;
        
        root->next =head;
        
        ListNode *first = root;
        
        ListNode *second = root;
        
        for(int i=0;i<n;i++){
            first = first->next;
        }
        
        while(first->next!=NULL){
            
            first = first->next;
            second = second->next;
            
        }
        
        ListNode *temp;
        temp = second->next->next;
        
        second->next =temp;
        
        return root->next;
    }
};