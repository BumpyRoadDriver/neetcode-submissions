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
    tuple<bool, int, int> isValidBSTAux(TreeNode *root){
        // returns boolean status, the smallest element and the largest element 
        // should only receive not null pointers
        int smallest = root -> val; 
        int largest = smallest;
        bool status = true;
        int cmp_left = largest -1;
        int cmp_right = largest+1;
        if (root -> left){
            tuple<bool, int, int> t_left = isValidBSTAux(root -> left);
            if (not get<0>(t_left)) return {0, -1001, -1001};
            smallest = get<1>(t_left);
            cmp_left = get<2>(t_left);
        }
        if (root -> right){
            auto t_right =isValidBSTAux(root -> right);
            if (!get<0>(t_right)) return {0, -1001, -1001};
            largest = get<2>(t_right);
            cmp_right = get<1>(t_right);
        }

        if (cmp_left < root -> val and root -> val < cmp_right){
            return {true, smallest, largest};
        }
        return {0, -1001, -1001};

    }

    bool isValidBST(TreeNode* root) {
        if (not root) return true; 
        return get<0>(isValidBSTAux(root));
    }
};
