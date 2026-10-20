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
    ListNode* reverseList(ListNode *head, int size){
        if (size <= 1) return head;

        ListNode *cur = head;
        ListNode *prev = nullptr;
        while(cur){
            ListNode *temp2 = cur;
            cur = cur -> next;
            temp2 -> next = prev; 
            prev = temp2;
        }
        return prev;

    }

    void reorderList(ListNode* head) {
        // we break off the list and save the second head of the list after n/2 
        // then simply we iterate over the first head and then add nodes in between 

        int n = 0; 
        ListNode*cur = head; 
        while(cur != nullptr){
            cur = cur -> next;
            n++;
        }
        if (n <= 2) return ;

        int t = (n+1)/2;
        cur = head; 
        while(--t){
            cur = cur -> next;
        }

        ListNode* head2 = cur -> next;
        cur->next = nullptr;
        head2 = reverseList(head2, n - (n+1)/2);
        ListNode *temp = head2; 
        cur = head;



        while(head2 != nullptr){
            temp = head2;
            head2 = head2 -> next;
            temp -> next = cur -> next;
            cur -> next = temp;
            cur = cur -> next ->next;
        }
        return;



    }
};
