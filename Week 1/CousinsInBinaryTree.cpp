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
    void dfs(TreeNode* root, int x, int y, int d, int &d1, int &d2, int &p1, int &p2)
    {
        if(root == NULL)    return;
        d = d + 1;
        
        if(root->val == x)
        {
            d1 = d;
            return;
        }
        if(root->val == y)
        {
            d2 = d;
            return;
        }
        
        if(root->left && root->left->val == x)    p1 = root->val;
        else if(root->left && root->left->val == y)   p2 = root->val;
        
        dfs(root->left, x, y, d, d1, d2, p1, p2);
        
        if(root->right && root->right->val == x)    p1 = root->val;
        else if(root->right && root->right->val == y)   p2 = root->val;

        dfs(root->right, x, y, d, d1, d2, p1, p2);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root == NULL)
            return false;
        
        int d = -1, d1 = 0, d2 = 0, p1 = 0, p2 = 0; 
        dfs(root, x, y, d, d1, d2, p1, p2);
        
        if(d1 == d2 && p1 != p2)
            return true;
        else
           return false;
    }
};