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

    
    unordered_map <int, int> mp;
    int maxi = 0;
    
    void dfs(TreeNode * root, vector <int> &temp, int count)
    {
        mp[root -> val] ++;
        temp.push_back(root -> val);
        
        if(!root->left && !root->right)
        {
            int count = 0;
            for(auto pair: mp)
            {
                if(pair.second % 2 != 0)
                    count ++;
            }
                        
            if(count <= 1)
                maxi++;
            
            mp[root->val] --;
            temp.pop_back();
            return;
        }
        
        
        // traverse left
        if(root -> left)
            dfs(root -> left, temp, count+1);
        
        // traverse right
        if(root -> right)
            dfs(root -> right, temp, count+1);
        
        mp[root->val] --;
        temp.pop_back();   
    }
 
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector <int> temp;
        dfs(root, temp, 0);
        
        return maxi;
        
    }
};