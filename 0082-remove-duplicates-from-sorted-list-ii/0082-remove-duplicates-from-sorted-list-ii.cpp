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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        vector <int> arr;
        unordered_map <int, int> mp;
        ListNode *temp = head;
        
        while(temp != nullptr)
        {
            mp[temp->val] ++;
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        
        // initialisation
        temp = new ListNode(0);
        temp -> next = head;
        bool flag = false;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(mp[arr[i]] == 1)
            {
                temp = temp -> next;
                temp -> val = arr[i];
                flag = true;
            }
        }
        
        if(!flag)
            return nullptr;
        
        temp -> next = nullptr;
        
        return head;
    }
};