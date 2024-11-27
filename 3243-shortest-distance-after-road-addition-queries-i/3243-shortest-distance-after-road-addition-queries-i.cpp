class Solution 
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++)    adj[i].push_back(i+1);
        
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            adj[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(get_shortest(adj));
        }
        return ans;
    }
    int get_shortest(vector<vector<int>>& adj)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        vector<int> vis(adj.size(), 0);
        
        while(!pq.empty())
        {
            int node = pq.top().second, dis = pq.top().first;
            pq.pop();
            if(vis[node])   continue;
            vis[node] = dis;
            
            if(node == adj.size()-1)    return dis;
            
            for(int i=0;i<adj[node].size();i++)
            {
                pq.push({dis+1, adj[node][i]});
            }
        }
        return 0;
    }
};