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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        
        
        if(l1==NULL&&l2==NULL) return nullptr;
        
        if(l1==NULL) return l2;
        
        if(l2==NULL) return l1;
        
        ListNode *root;
        
        root = l1;
        
        int carry=0;
        
        ListNode *temp;
        
        while(l1!=NULL&&l2!=NULL){
            
          l1->val =l1->val+l2->val+carry;
          
          if(l1->val>=10){
              l1->val = (l1->val)%10;
              carry = 1;
          }else{
              carry = 0;
          }
          
          temp = l1;
          
          l1 = l1->next;
          l2 = l2->next;
        }
        
        if(l2!=NULL){
            
            temp->next = l2;
            
           while(l2!=NULL){
                l2->val = l2->val +carry;
                if(l2->val>=10){
                    l2->val = (l2->val)%10;
                    carry = 1;
                }else{
                    carry = 0;
                }
                temp = l2;
                l2 = l2->next;
            }
            
        }else if(l1!=NULL){
            
            while(l1!=NULL){
                l1->val = l1->val +carry;
                if(l1->val>=10){
                    l1->val = (l1->val)%10;
                    carry = 1;
                }else{
                    carry = 0;
                }
                 temp = l1;
                 l1 = l1->next;
            }
        }
        
        
        if(carry){
            ListNode *high  = new ListNode(1);
            temp->next = high;
        }
        
        
        
        return root;
        
    }
};