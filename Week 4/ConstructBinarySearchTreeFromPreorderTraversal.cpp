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
// Time complexity :- O(n)
// Space complexity :- O(n)
class Solution {
public:
    TreeNode* buildBST(vector<int>&p, int &id, int low, int high)
    {
        if(id == p.size())
            return NULL;
        
        int val = p[id];
        if(val < low || high < val)
            return NULL;
        
        TreeNode* root = new TreeNode(val);
        id = id+1;
        
        root->left = buildBST(p, id, low, val-1);
        
        root->right = buildBST(p, id, val+1, high);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int id = 0;
        TreeNode* root = NULL;
        return buildBST(preorder, id, INT_MIN, INT_MAX);
    }
};