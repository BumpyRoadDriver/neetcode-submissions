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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*a = (p -> val < q -> val)? p: q; 
        TreeNode *b = (a == p)? q: p;
        if (a -> val <= root -> val and root -> val <= b -> val){
            return root;
        }
        else if (a -> val > root -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }
        else return lowestCommonAncestor(root -> left, p, q);
    }
};
