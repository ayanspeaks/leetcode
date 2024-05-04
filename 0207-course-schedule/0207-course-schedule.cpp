class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            topo.push_back(it);
            for(auto node:adj[it]){
                indegree[node]--;
                if(indegree[node] == 0)
                    q.push(node);
            }
        }
        if(topo.size() == n)
            return true;
        return false;
    }
};