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
    int height(TreeNode *root){
        if(not root) return 0;
        return 1 + max(height(root -> right),height(root -> left));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (not root) return 0;
        return max({height(root -> right) + height(root -> left), diameterOfBinaryTree(root -> right), diameterOfBinaryTree(root -> left)});
    }
};
