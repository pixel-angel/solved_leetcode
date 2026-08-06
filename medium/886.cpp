class Solution {
public:
    vector <vector<int>> g;
    vector <int> vis;
    bool ans=true;

    void dfs(int node,int color){
        vis[node]=color;
        for(auto v:g[node]){
            if(!vis[v]) dfs(v,3-color);
            else if(vis[v]==vis[node]){
                ans=false; break;
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vis.assign(n+1,0);
        g.assign(n+1,{});
        for(auto v:dislikes){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) dfs(i,1);
        }
        return ans;
        
    }
};