/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Naive Aproach
//         unordered_set<ListNode*> s;

//         while(head!=NULL) {
//             if(s.find(head)!=s.end()) {
//                 return head;
//             }

//             s.insert(head);
//             head=head->next;
//         }
//         return head;

        //Better Aproach
        ListNode* slow, *fast;
        slow = fast = head;
        while (fast and fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};