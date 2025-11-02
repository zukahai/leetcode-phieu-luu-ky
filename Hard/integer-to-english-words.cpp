#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string numberToWordsLen3(int n) {
        string res = "";
        // 21 đầu tiên
        vector <string> words = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                 "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                 "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
        vector <string> words2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        int a = n / 100;
        int b = (n / 10) % 10;
        int c = n % 10;

        if (a != 0) {
            res += words[a] + " " +  "Hundred ";
        }

        if (n % 100 != 0) {
            if (n % 100 <= 20) {
                res += words[n % 100] + " ";
            } else {
                res += words2[b] + " ";
                if (c != 0) {
                    res += words[c] + " ";
                }
            }
        }
        
        return res;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        vector <string> str = {"", "Thousand ", "Million ", "Billion "};
        int index = 0;
        string res = "";
        while (num > 0) {
            int n = num % 1000;
            string s = numberToWordsLen3(n);
            if (s.size() > 0)
                res = s + str[index] + res;
            num /= 1000;
            index++;
        }
        return res.substr(0, res.size() - 1);
    }
};

int main() {
    Solution sol;
    cout << sol.numberToWords(10000000);
}