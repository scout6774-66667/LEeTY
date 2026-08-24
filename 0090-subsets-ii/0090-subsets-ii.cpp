class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int>& nums, vector<int>& curr) {

        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate at same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);

            solve(i + 1, nums, curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> curr;

        solve(0, nums, curr);

        return ans;
    }
};