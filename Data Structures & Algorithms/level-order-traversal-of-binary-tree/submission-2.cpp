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
    int depth (TreeNode* root){
        if(not root) return 0;
        return 1 + max(depth(root -> left), depth(root -> right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (not root) return {};
        int max_depth =depth(root);
        vector<vector<int>> level_order_structure(max_depth);
        int k = 0;
        queue<TreeNode*> q; 
        q.push(root);
        while(q.size()){
            //int remove_items = q.size(); 
            vector<TreeNode*> temp_queue; 
            while(q.size()){
                auto u = q.front(); 
                temp_queue.push_back(u);
                level_order_structure[k].push_back(u->val);
                q.pop();
            }
            k++;
            
            for(TreeNode *child: temp_queue){
                if (child -> left){
                    q.push(child->left);
                }
                if (child -> right){
                    q.push(child -> right);
                }
            }
            temp_queue.clear();



        }

        return level_order_structure;

    }
};
