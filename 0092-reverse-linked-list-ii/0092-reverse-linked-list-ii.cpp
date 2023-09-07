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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        vector <int> res;
        
        while(head != NULL)
        {
            res.push_back(head -> val);
            head = head -> next;
        }
        
        reverse(res.begin()+left-1, res.begin() +right);
        
        ListNode * temp = new ListNode(res[0]);
        head = temp;
        
        for(int i=1; i<res.size(); i++)
        {
            temp -> next = new ListNode(res[i]);
            temp = temp->next;
        }
        
        return head;
    }
};