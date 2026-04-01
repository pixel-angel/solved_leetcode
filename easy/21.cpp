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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode *curr1 = list1, *curr2 = list2, *tail = NULL, *ans = NULL;

        // assign head and move to next pointer
        if(curr1->val > curr2->val) {
            ans = curr2;
            curr2 = curr2->next;
        } else {
            ans = curr1;
            curr1 = curr1->next;
        }

        // update tail
        tail = ans;

        while(curr1 != NULL && curr2 != NULL) {
            // compare
            if(curr1->val >= curr2->val) {
                // merge next node
                tail->next = curr2;
                // update to next node
                curr2 = curr2->next;
            } else {
                // merge next node
                tail->next = curr1;
                 // update to next node
                curr1 = curr1->next;
            }  
            // update tail
            tail = tail->next;
        }

        // merge remaining lists
        if(curr1 != NULL) tail->next = curr1;
        else tail->next = curr2;

        // return head
        return ans;
    }
};