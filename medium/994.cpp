class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int o = 0;
        int infected = 0;

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) o++;
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    infected++;
                }
            }
        }

        int xx[4] = {-1, 1, 0, 0};
        int yy[4] = {0, 0, -1, 1};   

        vector<vector<int>> vis(m, vector<int>(n, 0));

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();                  

            for (int i = 0; i < 4; i++) {
                int dx = x + xx[i];
                int dy = y + yy[i];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n &&
                    grid[dx][dy] == 1 && !vis[dx][dy]) {

                    vis[dx][dy] = 1;              
                    q.push({{dx, dy}, d + 1});    
                    ans = max(ans, d + 1);
                    infected++;
                }
            }
        }

        if (o != infected) return -1;
        return ans;
    }
};