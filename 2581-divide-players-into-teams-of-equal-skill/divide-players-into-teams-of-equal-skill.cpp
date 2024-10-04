class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if (skill.size() < 2) {
            return -1;
        }

        sort(skill.begin(), skill.end());

        int low = 0;
        int high = skill.size() - 1;

        long long chemistry = 0;
        int sum = skill[low] + skill[high];

        while (low < high) {
            if (skill[low] + skill[high] != sum) {
                return -1;
            }

            chemistry += (long long)skill[low] * skill[high];

            low++;
            high--;
        }

        return chemistry;
    }
};