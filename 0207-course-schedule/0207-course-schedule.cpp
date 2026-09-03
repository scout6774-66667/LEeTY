class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state) {

        // Currently visiting -> cycle found
        if (state[node] == 1) {
            return false;
        }

        // Already completely processed
        if (state[node] == 2) {
            return true;
        }

        // Mark as currently visiting
        state[node] = 1;

        // Visit all neighbors
        for (int neighbor : graph[node]) {

            if (!dfs(neighbor, graph, state)) {
                return false;
            }
        }

        // Mark as completely processed
        state[node] = 2;

        return true;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        // Build graph
        vector<vector<int>> graph(numCourses);

        for (auto& p : prerequisites) {

            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
        }

        // 0 = unvisited
        // 1 = visiting
        // 2 = completed
        vector<int> state(numCourses, 0);

        // Check every course
        for (int i = 0; i < numCourses; i++) {

            if (state[i] == 0) {

                if (!dfs(i, graph, state)) {
                    return false;
                }
            }
        }

        return true;
    }
};