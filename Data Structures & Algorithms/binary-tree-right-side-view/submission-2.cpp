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
    vector<int> rightSideView(TreeNode* root) {
        if (not root) return {};
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root); 
        
        while(!q.empty()){
            vector<TreeNode*> temp_queue;
            while(q.size()){
                TreeNode *u = q.front(); 
                q.pop();
                temp_queue.push_back(u);
            }
            ans.push_back(temp_queue.back() -> val);

            for(auto child: temp_queue){
                if (child -> left){
                    q.push(child -> left);
                }
                if (child -> right){
                    q.push(child -> right);
                }
            }
            // temp_queue.clear();


        }
        return ans;
    }
};
