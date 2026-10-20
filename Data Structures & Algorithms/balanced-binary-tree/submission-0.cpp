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
    bool isBalanced(TreeNode* root) {
        if (not root) return true;
        return isBalanced_aux(root).first;
    }

    pair<bool, int> isBalanced_aux(TreeNode *root){
        if(not root) return {true, 0}; 
        pair<bool, int> l = isBalanced_aux(root -> left);
        pair<bool, int> r = isBalanced_aux(root -> right);
        if ((not l.first) or (not r.first) or (abs(l.second - r.second) > 1)){
            return {false, 0};
        }
        return {true, 1+max(l.second, r.second)};
    }
};
