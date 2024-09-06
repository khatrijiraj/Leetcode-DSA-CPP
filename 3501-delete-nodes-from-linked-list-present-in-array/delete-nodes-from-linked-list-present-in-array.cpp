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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) {
            return head;
        }

        unordered_set<int> stt;
        for (auto& it : nums) {
            stt.insert(it);
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        while (current->next) {
            if (stt.find(current->next->val) != stt.end()) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return dummy->next;
    }
};