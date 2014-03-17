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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *answer,*root;
        
        root=new ListNode(-1);  
        answer=root;  
        
        while(true){
            if(l1==NULL){
                answer->next = l2;
                break;
            }
            
            if(l2==NULL){
                answer->next = l1;
                break;
            }
            
            if(l2->val>l1->val){
                answer ->next = l2;
               
                l2 = l2->next;
            }else{
                answer ->next = l1;
                l1 = l1->next;
            }
            answer = answer->next;
        }
        
        return root->next;
    }
};