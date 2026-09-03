class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state) {

        // Already in current DFS path
        // => cycle
        if (state[node] == 1)
            return false;

        // Already completed
        if (state[node] == 2)
            return true;

        // Mark as visiting
        state[node] = 1;

        // Visit neighbors
        for (int next : graph[node]) {

            if (!dfs(next, graph, state))
                return false;
        }

        // Finished
        state[node] = 2;

        return true;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        // Build graph
        vector<vector<int>> graph(numCourses);

        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        // 0 = not visited
        // 1 = visiting
        // 2 = finished
        vector<int> state(numCourses, 0);

        // Check every course
        for (int i = 0; i < numCourses; i++) {

            if (state[i] == 0) {

                if (!dfs(i, graph, state))
                    return false;
            }
        }

        return true;
    }
};