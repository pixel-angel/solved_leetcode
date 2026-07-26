class Solution {
public:
    using state= pair <pair<int,int>,int>;
    int xx[8]={-1,-1,-1,0,0,1,1,1};
    int yy[8]={-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector <vector<int>> vis(n,vector<int>(n,-1));
        queue <state> q;
        if(grid[0][0]!=0) return -1;
        q.push({{0,0},0});
        vis[0][0]=0;
        while(!q.empty()){
            state f=q.front();
            int x=f.first.first, y=f.first.second, d=f.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+xx[i], ny=y+yy[i];
                if(nx>=0 && ny<n && ny>=0 && nx<n && vis[nx][ny]==-1){
                    if(grid[nx][ny]==0){
                        q.push({{nx,ny},d+1});
                        vis[nx][ny]=d+1;
                    }
                }
            }
        }
        if(vis[n-1][n-1]!=-1) return vis[n-1][n-1]+1;
        return -1;
        
    }
};