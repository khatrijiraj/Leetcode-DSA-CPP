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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* current = head;
        while (current) {
            size++;
            current = current->next;
        }

        int part = size / k;
        int extra = size % k;

        current = head;

        vector<ListNode*> result(k, nullptr);

        for (int i = 0; i < k && current; i++) {
            result[i] = current;
            int currsize = 0;

            if (extra) {
                currsize = part + 1;
                extra--;
            } else {
                currsize = part;
            }

            for (int j = 1; j < currsize; j++) {
                current = current->next;
            }

            ListNode* save = current->next;
            current->next = nullptr;
            current = save;
        }
        return result;
    }
};