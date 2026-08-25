class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& nums, vector<bool>& used) {

        // Step 1: If current permutation is complete
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Step 2: Try every number
        for (int i = 0; i < nums.size(); i++) {

            // If this number is already used, skip it
            if (used[i]) {
                continue;
            }

            // Step 3: Choose the number
            used[i] = true;
            current.push_back(nums[i]);

            // Step 4: Recursively build the rest
            backtrack(nums, used);

            // Step 5: Undo the choice (BACKTRACK)
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> used(nums.size(), false);

        backtrack(nums, used);

        return ans;
    }
};