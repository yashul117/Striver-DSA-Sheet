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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

//         Naive Approach:
//         while(k--) {
//             ListNode* temp=head;
//             while(temp->next->next) {
//                 temp=temp->next;
//             }
//             ListNode* end=temp->next;

//             temp->next=NULL;
//             end->next=head;
//             head=end;
//         }
//         return head;

        ListNode* temp = head;
        int len = 1;

        while (temp->next) {
            len = len + 1;
            temp = temp->next;
        }
        temp->next = head;
        k = k % len;
        int cut = len - k;

        for (int i = 1; i < cut; i++) {
            head = head->next;
        }
        ListNode* newHead = head->next;
        head->next = NULL;

        return newHead;

    }
};