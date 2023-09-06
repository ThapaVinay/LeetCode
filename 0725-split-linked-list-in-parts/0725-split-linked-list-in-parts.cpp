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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        // count the total elements
        ListNode * temp = head;
        int count = 0;
        while(head != NULL)
        {
            head = head -> next;
            count ++;
        }
        
        // find quotient and remainder
        int q = count/k;
        int r = count%k;
        
        // every listNode will contain qoutient + remainder elements and remainder will decrement
        vector <ListNode*> res;
        head = temp;
        
        while(head != NULL)
        {
            res.push_back(head);
            
            int a = q-1;
            while(a > 0 && head)
            {
                head = head -> next;
                a --;
            }
            
            if(q > 0 && r > 0 && head)
            {
                head = head -> next;
                r --;
            }
            
            if(!head)
                break;
            
            ListNode * x = head -> next;
            head -> next = NULL;
            head = x;
            k--;
        }
        
        while(k > 0)
        {
            res.push_back(NULL);
            k--;
        }
        
        return res;
    }
};