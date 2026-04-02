class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        int vis[V]={0};
        while(! pq.empty()){
            auto it=pq.top();pq.pop();
            int node=it.second;
            int wt=it.first;
            
            if(vis[node])continue;
            
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adjList[node]){
                int adjNode=it.first;
                int edWt=it.second;
                if(!vis[adjNode]){
                    pq.push({edWt,adjNode});
                }
            }
        }
        return sum;
        
    }
};