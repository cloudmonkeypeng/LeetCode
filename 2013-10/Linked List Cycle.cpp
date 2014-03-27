
//Linked List Cycle

//Given a linked list, determine if it has a cycle in it.




#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode,*BiList;

bool hasCycle(ListNode *head) {
    
    if(head==NULL||head->next==NULL) return false;
    
    ListNode *fast = head;
    ListNode *slow = head;
    
    //while(fast->next!=NULL&&fast!=NULL)  is wrong
    
    while(fast!=NULL&&fast->next!=NULL){
        
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow)
            return true;
        
    }
    return false;
}

void CreateList(BiList &P){
    int data;
    cout<<"input"<<endl;
    scanf("%d",&data);
    if(data == -1){
        P= NULL;
    }else{
        P = (BiList)malloc(sizeof(ListNode));
        P->val = data;
        CreateList(P->next);
    }
    
}

int main(){

    BiList P = NULL;
    CreateList(P);
    cout<<hasCycle(P)<<endl;
}