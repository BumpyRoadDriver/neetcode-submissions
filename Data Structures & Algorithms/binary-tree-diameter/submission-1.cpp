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
    int size(TreeNode *root){
        if (!root) return 0 ;
        return 1 + max(size(root -> right), size(root -> left));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (not root) return 0;
        int l = 0, r = 0; 
        if (root -> left){l = size(root -> left);}
        if (root -> right){r = size(root -> right);}
        // cout << size(root -> right) << endl;
        // cout << l << " " << r << endl;
        return max({r + l, diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right)});
    }
};
