/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return nullptr;
        
        Node * temp1 = head;
        map <Node * , Node*> map;
        
        Node * new_head = new Node(head -> val);
        Node * temp2 = new_head;
        map[head] = new_head;
        head = head -> next;
        
        
        while(head != NULL)
        {
            Node * temp = new Node(head -> val);
            new_head -> next = temp;
            
            map[head] = temp;
        
            head = head -> next;
            new_head = new_head -> next;
        }
        
        new_head = temp2;
        
        while(temp1 != NULL)
        {
            temp2 -> random = map[temp1 -> random];
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        
        return new_head;
    }
};