class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Step 2: Traverse all intervals
        for (auto interval : intervals) {

            // Step 3: No overlap
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            }

            // Step 4: Overlap → merge
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};