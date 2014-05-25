class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        if(lists.size()==0) return nullptr;
        
        if(lists.size()==1) return lists[0];
        
        ListNode *p = lists[0];
        
        for(int i=1;i<lists.size();i++){
        
            p =mergeTwoLists(p,lists[i]);
        }
        
        return p;
    }
    
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