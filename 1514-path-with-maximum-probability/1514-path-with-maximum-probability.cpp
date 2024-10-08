class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        vector<double> dist(n, 0);  // Initialize distance/probability array with 0
        // Build the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].emplace_back(v, succProb[i]);
            adj[v].emplace_back(u, succProb[i]);
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});  // Start with probability 1 for the start node
        dist[start_node] = 1;      // Probability to reach start node is 1
        while (!pq.empty()) {
            auto [prob, node] = pq.top(); pq.pop();
            if (node == end_node)
                return prob;
            for (auto& [neighbor, cost] : adj[node]) {
                double newProb = prob * cost;
                if (newProb > dist[neighbor]) {
                    dist[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }
        return 0;
    }
};