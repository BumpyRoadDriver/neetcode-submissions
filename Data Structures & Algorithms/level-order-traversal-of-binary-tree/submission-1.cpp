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

    void traverse(TreeNode *root, int depth, vector<vector<int>> &structure){
        if (! root) return; // safeguard
        structure[depth].push_back(root -> val);

        if (root -> left){
            traverse(root -> left, depth+1, structure);
        }
        if (root -> right){
            traverse(root -> right, depth+1, structure);
        }
        return;

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (not root) return {};
        queue<TreeNode*> q; 
        q.push(root); 
        unordered_map<TreeNode*, int> dist;
        dist[root] = 0;
        int maxDepth = 0;

        // bfs
        while(q.size()){
            TreeNode *u = q.front(); 
            q.pop();

            if (u -> left){
                
                q.push(u -> left);
                maxDepth = dist[u] +1;
                dist[u -> left] = maxDepth;
            }
            if (u -> right){
                maxDepth = dist[u] + 1;
                dist[u->right] = maxDepth;
                q.push(u->right);
            }
        }

        vector<vector<int>> level_order_structure(maxDepth+1); 
        // then do an inorder dfs traversal? 
        traverse(root, 0, level_order_structure);        
        return level_order_structure;

        
    }
};
