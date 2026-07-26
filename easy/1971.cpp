class Solution {
public:
    vector <int> vis;
    vector <vector<int>> g;
    void dfs(int cur){
        vis[cur]=1;
        for(auto v:g[cur]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.assign(n,0);
        g.assign(n,{});
        for(auto v:edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        dfs(source);
        return vis[destination];
    }
};