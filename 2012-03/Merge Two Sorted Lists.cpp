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
            
            if(l2->val<l1->val){
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


//递归方法


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        ListNode *temp,*cur;
        
        if(l1->val<=l2->val){
            temp = mergeTwoLists(l1->next,l2);
            cur = l1;
        }else{
            temp = mergeTwoLists(l1,l2->next);
            cur =l2;
        }
        
        cur ->next = temp;
        
        return cur;
    }
};