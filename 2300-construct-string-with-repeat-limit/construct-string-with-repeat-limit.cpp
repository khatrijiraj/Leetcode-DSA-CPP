class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        if (s.empty()) {
            return "";
        }

        unordered_map<char, int> mpp;

        for (auto it : s) {
            mpp[it]++;
        }

        priority_queue<pair<char, int>> maxheap;

        for (auto it : mpp) {
            maxheap.push({it.first, it.second});
        }

        string result;

        while (!maxheap.empty()) {
            auto [ch, count] = maxheap.top();

            maxheap.pop();

            int used = min(repeatLimit, count);

            result.append(used, ch);

            count -= used;

            if (count > 0) {
                if (maxheap.empty()) {
                    break;
                }

                auto [nextch, nextcount] = maxheap.top();
                maxheap.pop();

                result += nextch;
                nextcount--;

                if (nextcount > 0) {
                    maxheap.push({nextch, nextcount});
                }

                maxheap.push({ch, count});
            }
        }

        return result;
    }
};