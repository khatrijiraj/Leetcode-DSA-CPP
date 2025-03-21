class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_set<string> stt(supplies.begin(), supplies.end());

        queue<int> qt;
        for (int i = 0; i < recipes.size(); i++) {
            qt.push(i);
        }

        vector<string> result;
        int lastsize = -1;

        while (static_cast<int>(stt.size()) > lastsize) {
            lastsize = stt.size();
            int size = qt.size();

            while (size-- > 0) {
                int reci = qt.front();
                qt.pop();
                bool ispossible = true;

                for (auto it : ingredients[reci]) {
                    if (!stt.count(it)) {
                        ispossible = false;
                        break;
                    }
                }

                if (!ispossible) {
                    qt.push(reci);
                } else {
                    stt.insert(recipes[reci]);
                    result.push_back(recipes[reci]);
                }
            }
        }

        return result;
    }
};
