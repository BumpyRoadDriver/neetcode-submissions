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
    void compute_size_subtree(TreeNode *root, unordered_map<TreeNode*, int> &size){
        if (not root){
            return;
        }
        else{
            compute_size_subtree(root -> left, size);
            compute_size_subtree(root -> right, size);
            if (root -> left) size[root] += size[root->left];
            if (root -> right) size[root] += size[root->right];
            size[root]++;
        }
    }

    int kthSmallestAux(TreeNode *root, int k, unordered_map<TreeNode*, int> &size){

        int order = (root -> left)? size[root -> left]+1:1;
        if (order == k) return root -> val;
        else if (order > k){
            return kthSmallestAux(root->left, k, size);
        }
        else{
            return kthSmallestAux(root -> right, k - order, size);
        }
    }

    int kthSmallest(TreeNode* root, int k) {

        unordered_map<TreeNode*, int> size;
        compute_size_subtree(root, size);
        // return 0;
        return kthSmallestAux(root, k, size);
    }

};
