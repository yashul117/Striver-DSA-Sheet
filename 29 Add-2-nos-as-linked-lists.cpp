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
//         ListNode* curr=new ListNode();

//         int carry=0;
//         while(l1 or l2) {
//             int temp=l1->val+l2->val;
//             if(temp>9) {
//                 carry=temp/10;
//                 temp=temp%10;
//             }
//             curr->next=temp+carry;

//         }

        ListNode* head = new ListNode();
        ListNode* curr = head;

        int carry = 0;

        while (l1 or l2 or carry)
        {
            int sum = 0;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;

            //make curr list
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            //update carry
            carry = sum / 10;
        }

        return head->next;

    }
};