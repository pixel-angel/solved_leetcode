class Solution {
public:
    int xx[4]={-1,1,0,0};
    int yy[4]={0,0,-1,1};
    using state= pair <pair<int,int>,int>;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //bfs on start.
        int m=maze.size(), n=maze[0].size(); 
        vector <vector<int>> vis(m,vector<int>(n,-1));
        queue <state> q;
        q.push({{entrance[0],entrance[1]},0});
        vis[entrance[0]][entrance[1]]=0;
        while(!q.empty()){
            state f=q.front();
            q.pop();
            int x=f.first.first, y=f.first.second, d=f.second;
            for(int i=0;i<4;i++){
                int nx=x+xx[i], ny=y+yy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && maze[nx][ny]=='.' && vis[nx][ny]==-1){
                    if(nx==m-1 || nx==0 || ny==n-1 || ny==0) return d+1;
                    q.push({{nx,ny},d+1});
                    vis[nx][ny]=d+1;
                }
            }
        }
        return -1;
    }
};