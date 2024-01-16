/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map <int, unordered_set<int>> mp;
    
    void traverse(TreeNode *root, int parent)
    {
        if(root == nullptr)
        {
            return;
        }
        
        if(parent != 0)
        {
            mp[parent].insert(root->val);
            mp[root -> val].insert(parent);
        }
        
        traverse(root->left, root->val);
        traverse(root->right, root->val);
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        traverse(root, 0);
        
        queue <int> q;
        q.push(start);
        
        unordered_set <int> visited;
        visited.insert(start);
        
        int count = -1;

        while(!q.empty())
        {
            int size = q.size();
       
            while(size > 0)
            {
                int front = q.front();
                q.pop();
                
                for(auto x: mp[front])
                {
                    if(visited.find(x) == visited.end())
                    {
                        q.push(x);
                        visited.insert(x);
                    }     
                }
                size --;
            }
            count ++;
        }
        return count;
    }
};