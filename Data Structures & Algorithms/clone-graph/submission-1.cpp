/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(unordered_map<int, bool> &visited, Node *old_node, Node *new_node, unordered_map<int, Node*> &node_map){
        visited[old_node -> val] = true; 

        for(auto v: old_node -> neighbors){
            if (!visited[v -> val]){
                Node *copied_node = new Node(v -> val); 
                new_node -> neighbors.push_back(copied_node);
                node_map[v->val] = copied_node;
                dfs(visited, v, copied_node, node_map);
            }
            else{
                new_node -> neighbors.push_back(node_map[v->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (not node) return nullptr; 
        Node *root = new Node(1); 
        unordered_map<int, Node*> node_map; 
        node_map[1] = root; 
        unordered_map<int,bool> visited; 

        dfs(visited, node, root, node_map);
        return root;
    }
};
