/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

    if(head==NULL)	 return head;

    RandomListNode *cur;

    cur= head;

    while(cur!=NULL){

    	RandomListNode *node = new RandomListNode(cur->label);

    	node->next = cur->next;

    	cur->next = node;

    	cur = node->next;
    }

    cur = head;

    RandomListNode *newCur;

    while(cur!=NULL){

    	newCur = cur->next;

    	if(cur->random!=NULL){
    		newCur->random = cur->random->next;
    	}else{
    		newCur->random = NULL;
    	}
    	
    	cur = cur->next->next;
    }

    cur = head;

    RandomListNode *answer;

    answer = head->next;


     while(cur!=NULL){

    	newCur = cur->next;

    	cur->next = cur->next->next;

    	cur = cur->next;

    	if(cur!=NULL){
    		newCur->next = newCur->next->next;
    	}else{
    		newCur->next = NULL;
    	}
    	
    }

    return answer;
        
    }
};