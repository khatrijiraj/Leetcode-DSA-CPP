class Solution {
public:
    vector<string> below20 = {"",        "One",       "Two",      "Three",
                              "Four",    "Five",      "Six",      "Seven",
                              "Eight",   "Nine",      "Ten",      "Eleven",
                              "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> belowtens = {"",       "",      "Twenty", "Thirty",
                                "Forty",  "Fifty", "Sixty",  "Seventy",
                                "Eighty", "Ninety"};

    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        int i = 0;
        string result = "";

        while (num) {
            if (num % 1000 != 0) {
                result = solve(num % 1000) + (i > 0 ? thousands[i] : "") + " " +
                         result;
            }
            num /= 1000;
            i++;
        }

        // Remove any trailing spaces
        while (result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }

    string solve(int num) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return below20[num] + " ";
        } else if (num < 100) {
            return belowtens[num / 10] + " " + solve(num % 10);
        } else {
            return below20[num / 100] + " Hundred " + solve(num % 100);
        }
    }
};
