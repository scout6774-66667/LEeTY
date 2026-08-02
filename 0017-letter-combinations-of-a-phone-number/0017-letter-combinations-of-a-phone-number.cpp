class Solution {
public:

    vector<string> ans;

    string phone[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, int index, string curr)
    {
        // If all digits are used
        if(index == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        // Letters for current digit
        string letters = phone[digits[index] - '0'];

        // Try every letter
        for(char ch : letters)
        {
            solve(digits, index + 1, curr + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};