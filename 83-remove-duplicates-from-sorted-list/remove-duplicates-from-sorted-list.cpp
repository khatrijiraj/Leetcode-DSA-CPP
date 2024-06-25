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
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* current = head;
        while (current->next) {
            if (current->val == current->next->val) {
                ListNode* save = current->next;
                current->next = save->next;
                delete save;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};