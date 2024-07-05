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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* save = head->next->next;

        vector<int> critical;
        int index = 1;

        while (save) {
            if ((curr->val > prev->val && curr->val > save->val) ||
                (curr->val < prev->val && curr->val < save->val)) {
                critical.push_back(index);
            }
            prev = curr;
            curr = save;
            save = save->next;
            index++;
        }

        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        int maxDistance = critical.back() - critical.front();

        for (int i = 1; i < critical.size(); i++) {
            minDistance = min(minDistance, critical[i] - critical[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};