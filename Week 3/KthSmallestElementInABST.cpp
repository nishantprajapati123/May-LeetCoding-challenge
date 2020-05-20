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
    void inOrderTraverse(TreeNode* root, int ans[], int k)
    {
        if(root == NULL)    return;
        
        inOrderTraverse(root->left, ans, k);
        if(++ans[0] == k)
        {
            ans[1] = root->val;
            return;
        }
        inOrderTraverse(root->right, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans[2] = {0,0};
        inOrderTraverse(root, ans, k);
        return ans[1];
    }
};