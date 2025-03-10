class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long long countOfSubstrings(string word, int k) {
        long long count = 0;

        int left = 0;
        int right = 0;

        unordered_map<char, int> mpp;
        int conso = 0;

        vector<int> nextConsonant(word.size());

        int nextconso = word.size();

        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextconso;
            if (!isVowel(word[i])) {
                nextconso = i;
            }
        }

        while (right < word.size()) {
            char ch = word[right];
            if (isVowel(ch)) {
                mpp[ch]++;
            } else {
                conso++;
            }

            while (conso > k) {
                char lefti = word[left];
                if (isVowel(lefti)) {
                    mpp[lefti]--;
                    if (mpp[lefti] == 0) {
                        mpp.erase(lefti);
                    }
                } else {
                    conso--;
                }
                left++;
            }

            while (left < word.size() && mpp.size() == 5 && conso == k) {
                count += nextConsonant[right] - right;
                char lefti = word[left];
                
                if (isVowel(lefti)) {
                    mpp[lefti]--;
                    if (mpp[lefti] == 0) {
                        mpp.erase(lefti);
                    }
                } else {
                    conso--;
                }

                left++;
            }
            
            right++;
        }

        return count;
    }
};