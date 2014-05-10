
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *insertionSortList(ListNode *head) {
    
    if(head==NULL||head->next==NULL) return head;
    
    ListNode *root =new ListNode(-1);
    
    root->next = head;
    
    ListNode *cur = head->next;
    
    ListNode *prev = head;
    
    
    while(cur!=NULL){
        
        ListNode *tempPrev = root;
        
        ListNode *temp = root->next;
        
        bool bInsert = false;
        
        while(temp!=cur){
        
            if(cur->val<temp->val){
                bInsert = true;
                break;
            }
            
            tempPrev =temp;
            temp = temp->next;
        }
        
        if(bInsert){
            
            prev->next = cur->next;
            
            tempPrev->next = cur;
            
            cur->next = temp;
            
            cur = prev->next;
        
        }else{
            prev =cur;
            cur = cur->next;
        }
    }
    
    return root->next;

}

int main(){
    
    
    ListNode *first =new ListNode(8);
    
    ListNode *second =new ListNode(5);
    
    ListNode *third =new ListNode(7);
    
    ListNode *fourth =new ListNode(9);
//    
    ListNode *fifith =new ListNode(8);
    
    first->next = second;
    
    second->next = third; third->next = fourth; fourth->next = fifith;
    
    ListNode *temp;
    
    //temp = first;
    
    temp = insertionSortList(first);
    
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
   
}