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
    ListNode* rotateRight(ListNode* head, int k) {
        
        vector<int> arr;
        ListNode *temp = head;
        int size = 0;
        
        while(temp != nullptr)
        {
            size ++;
            arr.push_back(temp -> val);
            temp = temp->next;
        }
        
        vector <int> arr1(size + 1);
        for(int i=0; i<arr.size(); i++)
        {
            arr1[(i+k)%size] = arr[i];
        }
        
        temp = head;
        int j = 0;
        while(temp != nullptr)
        {
            temp -> val = arr1[j++];
            temp = temp -> next;
        }
        
        return head;
    }
};