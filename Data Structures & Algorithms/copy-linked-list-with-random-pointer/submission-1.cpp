class Solution {
public:
    Node* copyRandomList(Node* head) {
        // unordered_set<Node*, int> dist; 
        // unordered_set<Node*,int> dist_copy;
        vector<Node*> dist, dist_copy;
        if (head == nullptr) return nullptr;
        map<Node*, int> distance_to_head;
        Node* cur = head ->next; 
        dist.push_back(head);
        Node *head_copy = new Node(head -> val);
        Node *cur_copy = head_copy;
        dist_copy.push_back(cur_copy);
        distance_to_head[head] = 0;
        distance_to_head[cur_copy] = 0;

        int d= 1;
        while(cur != nullptr){
            distance_to_head[cur] = d;
            Node* newNode = new Node(cur -> val);
            cur_copy -> next = newNode; 
            cur_copy = newNode;
            distance_to_head[newNode] = d++;
            dist.push_back(cur);
            dist_copy.push_back(newNode);
            cur = cur -> next;
            cur_copy = newNode;
        }

        cur = head;
        cur_copy = head_copy;
        while(cur != nullptr){
            if (cur -> random){
            int random_distance = distance_to_head[cur -> random];
            cur_copy -> random = dist_copy[random_distance];

            }
            else{
                cur_copy -> random = nullptr;
            }
            cur_copy = cur_copy -> next;
            cur = cur ->next;
        }

        return head_copy;
    }
};

