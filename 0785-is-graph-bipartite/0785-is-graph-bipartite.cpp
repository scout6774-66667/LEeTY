class Solution {
public:

    bool dfs(int node, int currentColor,
             vector<int>& color,
             vector<vector<int>>& graph) {

        // Give current node a color
        color[node] = currentColor;

        // Visit all neighbors
        for (int neighbor : graph[node]) {

            // Neighbor is not colored yet
            if (color[neighbor] == -1) {

                // Give opposite color
                if (!dfs(neighbor, 1 - currentColor,
                         color, graph)) {
                    return false;
                }
            }

            // Neighbor has same color
            else if (color[neighbor] == currentColor) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 = unvisited
        //  0 = color 0
        //  1 = color 1
        vector<int> color(n, -1);

        // Graph may be disconnected
        for (int i = 0; i < n; i++) {

            // Start DFS for a new component
            if (color[i] == -1) {

                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};