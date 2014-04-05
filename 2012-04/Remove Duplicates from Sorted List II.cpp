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
    ListNode *deleteDuplicates(ListNode *head) {
        
        
        if(head == NULL||head->next==NULL) return head;  
        
        ListNode *root; 
        
        root->next = head;
        
        ListNode *pre = head;
        
        ListNode *now = root;
        
        while(pre!=NULL)  {  
            bool isDup = false;
            
            while(pre->next!=NULL && pre->val == pre->next->val)  {
                isDup = true;
                pre = pre->next;
            }
            
            if(isDup){  
                pre = pre->next;
                continue;
            }
            
            now->next = pre;
            now = now->next;
            pre= pre->next;
        }
        
        now->next =NULL;  
        return root->next; 
    }
};