class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, int target,
                   vector<int>& candidates,
                   vector<int>& path) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            if (candidates[i] > target)
                continue;

            path.push_back(candidates[i]);

            // i, not i+1 → reuse allowed
            backtrack(i, target - candidates[i],
                      candidates, path);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> path;
        backtrack(0, target, candidates, path);

        return ans;
    }
};