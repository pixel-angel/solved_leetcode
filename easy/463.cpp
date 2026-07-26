class Solution {
public:
    int ans = 0;
    int row, col;
    vector<vector<int>> vis;
    int xx[4] = {-1, 1, 0, 0}, yy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>> &grid, int x, int y) {
        if (grid[x][y] == 1)
            ans += 4;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int dx = x + xx[i], dy = y + yy[i];
            if (dx >= 0 && dx < row && dy >= 0 && dy < col &&
                grid[dx][dy] == 1) {
                ans--;
                if (!vis[dx][dy])
                    dfs(grid, dx, dy);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vis.assign(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return ans;
                }
            }
        }
        return ans;
    }
};