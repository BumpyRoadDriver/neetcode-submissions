/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int countNodes(ListNode* head){
        int ans = 0; 
        ListNode *cur = head; 
        while(cur != nullptr){
            ans++;
            cur = cur -> next;
        }
        return ans;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int numNodes = countNodes(head);
        if (numNodes ==1 ){
            delete(head);
            return nullptr;
        } 
        // pos from back is a and actual pos is b then a+b = numNodes +1 
        // this means actual pos = numNodes +1 - a 
        int pos = numNodes+1-n;
        ListNode *cur = head; 

        if (pos == 1){
            head = cur->next;
            delete(cur);
            return head;
        }
        pos--;
        while(--pos){
            cur = cur -> next;
        }
        ListNode *temp = cur -> next;
        cur -> next = temp -> next;
        delete(temp); 
        return head;


    }
};
