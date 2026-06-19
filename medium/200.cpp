class Solution {
public:
    void bfs(int i,int j, vector<vector<int>>& vis,vector<vector<char>>& grid,int r,int c ){
        //bfs queue
        queue <pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            //check upar
                if(x-1>=0 && grid[x-1][y]=='1' && !vis[x-1][y]){
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                }
            //neeche
            if(x+1<r && grid[x+1][y]=='1' && !vis[x+1][y]){
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
            //left
            if(y-1>=0 && grid[x][y-1]=='1' && !vis[x][y-1]){
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
            //right
            if(y+1<c && grid[x][y+1]=='1' && !vis[x][y+1]){
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        //just use dfs or bfs
        
        //vis matrix
        int ans=0;
        vector <vector<int>> vis(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    //do bfs. i.e keep marking uske saath waale land saathi as vis
                    //and island++
                    bfs(i,j,vis,grid,rows,cols);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};