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
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n == 1)
        {
            vector <TreeNode*> temp;
            temp.push_back(new TreeNode(0));
            return temp;
        }
        
        
        vector <TreeNode*> res;
        for(int i=1; i<n; i+=2)
        {
            vector <TreeNode*> left = allPossibleFBT(i);
            vector <TreeNode*> right = allPossibleFBT(n-i-1);
            
            for(auto l: left)
            {
                for(auto r : right)
                {
                    TreeNode * root = new TreeNode(0,l,r);
                    res.push_back(root);
                }

            }
        }
        return res;
    }
};