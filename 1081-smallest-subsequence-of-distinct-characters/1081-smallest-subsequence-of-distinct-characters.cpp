class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> last(26);

        // Store last position of each character
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> used(26, false);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Skip if already added
            if (used[ch - 'a'])
                continue;

            // Remove bigger characters if they appear again later
            while (!ans.empty() &&
                   ans.back() > ch &&
                   last[ans.back() - 'a'] > i) {

                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += ch;
            used[ch - 'a'] = true;
        }

        return ans;
    }
};