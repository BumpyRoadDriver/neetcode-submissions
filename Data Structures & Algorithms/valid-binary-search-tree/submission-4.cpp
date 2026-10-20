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
    bool isValidAux(TreeNode *root, pair<int,int> range){
        auto [l, r] = range; 
        bool ans = (l < (root -> val) and (root -> val) < r); 
        if (not ans) return false;
        if (root -> left) ans&= isValidAux(root -> left, {l, root -> val});
        if (not ans) return false;
        if (root -> right) ans &= isValidAux(root -> right, {root -> val, r});
        return ans;
    }

    bool isValidBST(TreeNode* root) {
        if (not root) return true;
        pair<int, int> range = {-1e9-1, 1e9+1}; // basically infinity at start
        return isValidAux(root, range);
    }
};
