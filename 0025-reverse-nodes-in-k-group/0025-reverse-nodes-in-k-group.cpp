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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count = 0;
        ListNode *curr = head;
        
        while(curr != nullptr)
        {
            curr = curr -> next;
            count ++;
        }
        
        int size = count / k;
        
        ListNode *prev = nullptr;
        curr = head;
        
        ListNode * new_head = nullptr;
        
        ListNode * res = nullptr;
        
        while(size -- && head != nullptr)
        {
            prev = nullptr;
            ListNode * temp_head = curr;
            
            int x = k;
            
            while(x-- && curr != nullptr)
            {
                ListNode *temp = curr -> next;
                curr -> next = prev;

                prev = curr;
                curr = temp;
            }
            
            if(new_head != nullptr)
            {
                new_head -> next = prev;
            }
            new_head = temp_head;
            
            if(res == nullptr)
                res = prev;
            
        }
        
        if(curr != nullptr)
            new_head -> next = curr;
        
        return res;
        
    }
};