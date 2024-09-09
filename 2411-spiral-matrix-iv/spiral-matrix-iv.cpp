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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};;

        ListNode* current = head;

        int x = 0;
        int y = 0;
        int dir = 0;
        while (current) {
            result[x][y] = current->val;
            current = current->next;

            int newx = x + directions[dir].first;
            int newy = y + directions[dir].second;

            if (newx < 0 || newx >= m || newy < 0 || newy >= n ||
                result[newx][newy] != -1) {
                dir = (dir + 1) % 4;
                newx = x + directions[dir].first;
                newy = y + directions[dir].second;
            }

            x = newx;
            y = newy;
        }
        return result;
    }
};