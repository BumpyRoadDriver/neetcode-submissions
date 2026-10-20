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
    int dfs(TreeNode *root, int mx){
        if (not root) return 0;
        bool i = false;    
        if (mx <= root -> val){
            i = true;
            mx = root -> val;
        }
        return (int)(i)+ (dfs(root -> left, mx) + dfs(root -> right, mx));

    }

    int goodNodes(TreeNode* root) {
        return dfs(root, -10000);
    }
};
