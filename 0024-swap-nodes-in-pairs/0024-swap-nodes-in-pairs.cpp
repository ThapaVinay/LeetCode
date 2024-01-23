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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *ans = head -> next;
        ListNode *prev = nullptr;
        
        while(head != nullptr && head -> next != nullptr)
        {
            
            
            ListNode * temp = head;
            head = head -> next;
            
            // swapping
            temp -> next = head -> next;
            head -> next = temp;
            
            if(prev != nullptr)
            {
                prev -> next = head;
            }
            
            prev  = temp;
            head = temp -> next;
        }
        
        return ans;
        
    }
};