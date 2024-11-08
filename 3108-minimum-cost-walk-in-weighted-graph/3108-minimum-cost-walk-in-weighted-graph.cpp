class Solution {
    map<int, vector<pair<int, int>>> mp;   
    map<int, int> mapper; 
    map<int, int> distance; 
    set<int> visited;  
public:
    int bfs(int k, int comp){
        
        visited.insert(k);
        mapper[k] = comp;
        
        queue<int> q;
        q.push(k);
        int dist = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(pair<int, int> p : mp[node]){
                int v = p.first;
                int w = p.second;
                
                if((dist > (dist & w)) || visited.find(v)==visited.end()){
                    q.push(v);
                    visited.insert(v);
                    mapper[v] = comp;
                    dist = (dist & w);
                }
            }
        }
        if(dist==INT_MAX)
            return 0;
        return dist;
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        
        for(vector<int> v : edges){
            mp[v[0]].push_back({v[1], v[2]});
            mp[v[1]].push_back({v[0], v[2]});
        }
        
        
       
        int comp=1;
        for(int i=0;i<n;i++){
            
            if(visited.find(i)==visited.end()){
                int dist = bfs(i, comp);
                distance[comp] = dist;
                comp++;
            }
        }
        
        vector<int> res;
        for(vector<int> V : query){
            int u = V[0];
            int v = V[1];
            if(u==v){
                res.push_back(0);
                continue;
            }
            
            if(mapper.find(u) == mapper.end() || mapper.find(v) == mapper.end() ||mapper[u]!=mapper[v])
                res.push_back(-1);
            else
                res.push_back(distance[mapper[u]]);
        }
        return res;
    }
};