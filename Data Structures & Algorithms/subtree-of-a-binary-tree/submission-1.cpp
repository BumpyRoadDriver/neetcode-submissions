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
    bool sameTree(TreeNode *p, TreeNode *q){
        if (not p and not q) return true;
        else if (not p or not q) return false; 
        return (p -> val == q -> val) and sameTree(p -> right, q->right) and sameTree(p -> left , q -> left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if (not root and not subroot){return true;}
        // else if (not root or not subroot) return false;
        if (not root and not subRoot) return true;
        else if (not root or not subRoot) return false;
        return sameTree(root, subRoot) or isSubtree(root -> left, subRoot) or isSubtree(root -> right, subRoot);


    }
};
