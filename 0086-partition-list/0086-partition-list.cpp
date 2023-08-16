/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 // */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *list1 = new ListNode(0);
        ListNode *list2 = new ListNode(0);
        
        ListNode * l1 = list1;
        ListNode * l2 = list2;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                
                list1 -> next = head;
                list1 = list1 -> next;
               
            }
            else{
                list2->next = head;
                list2 = list2 -> next;
            }
            
            head = head -> next;
        }
        list2 -> next = nullptr;
        list1->next = l2->next;
        return l1->next;
    }
};