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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)
            return false;
        
        ListNode *prev = head;
        ListNode *curr = head -> next;
        
        while(prev != NULL && curr != NULL && prev->next != NULL && curr->next != NULL)
        {
            if(prev == curr)
            {
                return true;
            }
            prev = prev -> next;
            curr = curr -> next -> next;
        }
        return false;
    }
};