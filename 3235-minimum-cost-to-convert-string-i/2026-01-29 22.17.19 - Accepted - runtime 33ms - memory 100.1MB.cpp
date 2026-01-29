class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // 1. Initialize Distance Matrix
        // Use a large constant for infinity, but safe enough to avoid overflow during addition
        const long long INF = 1e18; 
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        
        // Distance to self is always 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // 2. Build the Graph
        // Store the minimum direct cost between characters
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 3. Floyd-Warshall Algorithm (All-Pairs Shortest Path)
        // Complexity: O(26^3) - Constant time relative to string length
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // 4. Calculate Total Cost
        long long totalCost = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                
                // If path is impossible, return -1
                if (dist[u][v] == INF) return -1;
                
                totalCost += dist[u][v];
            }
        }

        return totalCost;
    }
};