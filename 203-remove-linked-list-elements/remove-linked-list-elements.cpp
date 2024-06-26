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

    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* current = head;

        while (current) {
            if (current->val == val) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }

                ListNode* save = current;
                current = current->next;
                delete save;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};