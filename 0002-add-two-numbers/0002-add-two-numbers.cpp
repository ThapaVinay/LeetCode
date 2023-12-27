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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        int carry = 0;
        ListNode * head = l1;
        ListNode * temp1;
        
        while(l1 != NULL && l2  != NULL)
        {
            int sum = carry + l1->val + l2->val;
            
            int temp = sum % 10;
            carry = sum/ 10;
            
            l1 -> val = temp;
            
            if(l1 != NULL && l1 -> next == NULL)
                temp1 = l1;
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1 != NULL)
        {
            int sum = carry + l1->val;
            
            int temp = sum % 10;
            carry = sum/ 10;
            
            l1 -> val = temp;
            temp1 = l1;
            l1 = l1 -> next;
            
           
        }
        
        while(l2 != NULL)
        {
            int sum = carry + l2->val;
            
            int temp = sum % 10;
            carry = sum/ 10;
             
            ListNode * ptr = new ListNode(temp);
            temp1 -> next = ptr;
            temp1 = temp1 -> next;
            l2 = l2->next;
        }
        
        if(carry != 0)
        {
            ListNode * ptr = new ListNode(carry);
            temp1 -> next = ptr;
            temp1 = temp1 -> next;
        }
        
        return head;
        
    }
};