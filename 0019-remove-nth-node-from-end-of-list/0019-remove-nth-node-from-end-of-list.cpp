/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head -> next == NULL)
            return head -> next;
        
        ListNode * temp = head;
        
        int count = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            count ++;
        }
        
        int rem = count - n;
        
        temp = head;
        
        while(rem > 1)
        {
            temp = temp -> next;
            rem --;
        }
        
        if(n == count)
        {
            head = head -> next;
        }
        else
            temp -> next = temp -> next -> next;
        
        return head;
    }
};