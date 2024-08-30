class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> ans;
    for (auto it: edges) {
        if(it[2]==-1) continue;
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
   q.push({0,source});
   vector<int> dist(n,1e9);
   dist[source]=0;
   while(!q.empty()){
       int cur_dist=q.top().first;
       int node=q.top().second;
       q.pop();
       if(node==destination) break;

       for(auto it:adj[node]){
           int adjnode=it.first;
           int wt=it.second;
           if(cur_dist+wt<dist[adjnode]){
               dist[adjnode]=cur_dist+wt;
               q.push({dist[adjnode],adjnode});
           }
       }
   }
   if(dist[destination]<target){
       return {};
   }
   if(dist[destination]==target){
       for(auto &it:edges){
           if(it[2]==-1){
               it[2]=1e9;
           }
       }
       return edges;
   }
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   for(int i=0;i<edges.size();i++){
       auto &it=edges[i];
       if(edges[i][2]==-1){
           edges[i][2]=1;
           adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
           adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});

           while(!pq.empty()){
                pq.pop();
            }
       //Dijkstra
       pq.push({0,source});
       vector<int> dist(n,1e9);
       dist[source]=0;
       while(!pq.empty()){
       int cur_dist=pq.top().first;
       int node=pq.top().second;
       pq.pop();
       if(node==destination) break;

       for(auto it:adj[node]){
          int adjnode=it.first;
           int wt=it.second;
           if(cur_dist+wt<dist[adjnode]){
               dist[adjnode]=cur_dist+wt;
               pq.push({dist[adjnode],adjnode});
           }
       }
   }

   if(dist[destination]<=target){
       it[2]+=target-dist[destination];

       for(int j=i+1;j<edges.size();j++){
           if(edges[j][2]==-1){
               edges[j][2]=1e9;
           }
       }
       return edges;
       }
       }

   }
   return {};
}
};