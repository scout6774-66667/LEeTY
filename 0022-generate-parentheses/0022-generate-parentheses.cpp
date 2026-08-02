class Solution {
public:

    vector<string> ans;

    void solve(string curr, int open, int close, int n)
    {
        // If the string is complete, save it
        if (curr.length() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still have some left
        if (open < n)
        {
            solve(curr + "(", open + 1, close, n);
        }

        // Add ')' only if it won't make the string invalid
        if (close < open)
        {
            solve(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        solve("", 0, 0, n);
        return ans;
    }
};