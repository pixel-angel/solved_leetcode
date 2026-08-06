class Solution {
public:
    bool ans=true;
    vector<int> vis;
    void dfs(vector<vector<int>>&g, int node, int color){
        vis[node]=color;
        for(auto v:g[node]){
            if(!vis[v]){
                dfs(g,v,3-color);
            }
            else if(vis[v]==vis[node]) ans= false;
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.assign(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,i,1);
        }
        return ans;
    }
};