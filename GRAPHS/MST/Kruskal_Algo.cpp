
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &adjLs) {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(auto it:adjLs){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            edges.push_back({wt,{u,v}});
        } 
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mst=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mst+=wt;
                ds.unionByRank(u,v);
            }
        }
        return mst;
    }
};