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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, *cur2 = l2;
        ListNode *cur = nullptr, *head = nullptr, *tail = nullptr; 
        if (not l1) return l2;
        if (not l2) return l1;
        bool carry = false;
        while(cur1 and cur2){
            int digit_sum = (cur1 -> val + cur2 -> val) + carry;
            carry = (digit_sum) >= 10; digit_sum %= 10;
            cur1 -> val = digit_sum; 
            cur2 -> val = digit_sum;
            cout << cur2 -> val << endl;
            cout << digit_sum << endl;
            cout << carry << endl;


            if (cur1 -> next == nullptr){
                cout << "This happened" << endl;
                tail = cur2;
                cur = cur2;
                head = l2;
                break;
            }
            else if (cur2 -> next == nullptr){
                tail = cur1;
                cur = cur1; 
                head = l1;   
                break;
            }
            cur1 = cur1 -> next; cur2 = cur2 -> next;
        }

        while(carry and cur -> next){
            cur -> next -> val = ((cur -> next -> val) + carry) % 10 ;
            carry = ((cur -> next -> val) == 0);
            cur = cur -> next;
            
        }
        if (carry){
            cur -> next = new ListNode(1);
        }

        cout << "First" << endl;
        for(auto it = l1; l1; l1 = l1 -> next){
            cout << it -> val << " ";
        }
        cout << endl;
        cout << "Second" << endl;
        for(auto it = l2; l2; l2 = l2 -> next){
            cout << it -> val << " ";
        }
        return head;


    }
};
