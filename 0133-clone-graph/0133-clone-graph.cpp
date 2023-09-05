/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        queue <Node*> q;
        unordered_map <Node* , Node*> mp;
        
        if(!node)
            return nullptr;
        
 
        
        q.push(node);
        while(!q.empty())
        {
            Node * temp = q.front();
            q.pop();
            
            mp[temp] = new Node(temp->val);
            
            for(int i=0; i<temp->neighbors.size(); i++)
            {
                if(mp[temp -> neighbors[i]] == NULL)
                {
                    mp[temp -> neighbors[i]] = new Node(temp -> neighbors[i]->val);
                    q.push(temp->neighbors[i]);
                }
                    
            }
        }
        
        for(auto pair: mp)
        {
            vector <Node*> n;
            for(int i=0; i<pair.first -> neighbors.size() ;i++)
            {
                n.push_back(mp[pair.first->neighbors[i]]);
            }
            pair.second -> neighbors = n;
        }
        
        return mp[node];
    }
};