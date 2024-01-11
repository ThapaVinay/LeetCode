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
    int maxi = 0;
    
    void traverse (TreeNode * root, int a , int b)
    {
        if(root == NULL)
            return;
        
        maxi = max(maxi, max(abs(root->val - a), abs(root -> val - b)));
        
        traverse(root -> left, max(a,root -> val), min(b, root -> val));
        traverse(root -> right, max(a,root -> val), min(b, root -> val));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int a = root -> val, b = root -> val;
        
        traverse(root, a, b);
        return maxi;
    }
};