class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto& it : details) {
            int n = it.size();
            string temp = "";
            temp += it[n - 4];
            temp += it[n - 3];
            int age = stoi(temp);
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};