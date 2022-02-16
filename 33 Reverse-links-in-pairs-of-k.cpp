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
    ListNode* reverseKGroup(ListNode* head, int k) {
//         vector<int> v;
//         ListNode* ptr=head;

//         while(ptr) {
//             v.push_back(ptr->val);
//             ptr=ptr->next;
//         }

//         int i=0;
//         int n=v.size();

//         for(int i=0;i<n;i=i+k)
//         {
//             if(i+k<=n)
//             {
//                 reverse(v.begin()+i,v.begin()+i+k);
//             }
//         }

//         ListNode* curr=head;

//         int j=0;
//         while(curr)
//         {
//             curr->val=v[j++];
//             curr=curr->next;
//         }

//         return head;

        ListNode* newList = new ListNode();
        newList->next = head;
        ListNode* prev = newList;
        ListNode* cur = newList;
        ListNode* nex = newList;

        ListNode* ptr = head;
        int n = 0;
        while (ptr) {
            n++;
            ptr = ptr->next;
        }

        int i = 0;
        while (i + k <= n) {
            cur = prev->next;
            nex = cur->next;
            for (int j = 1; j < k; j++) {
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            i += k;
        }

        return newList->next;
    }
};