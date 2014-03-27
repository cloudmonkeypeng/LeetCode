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
     ListNode *detectCycle(ListNode *head)  
    {  
        if (!head || !head->next) return nullptr;  
        ListNode *slow = head->next;  
        ListNode *fast = head->next->next;  
        while (fast && fast != slow)  
        {  
            slow = slow->next;  
            fast = fast->next? fast->next->next:fast->next;  
        }  
        if (!fast) return nullptr;  
        for (fast = head; fast != slow; fast = fast->next) slow = slow->next;  
        return slow;  
    }  
};