class Solution {
    template<typename T>
    using v = vector<T>;

    int m, n;
    v<v<int>> dirn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    v<v<bool>> vis;

    int solve(int i, int j, v<v<int>>& grid) {
        int ans = 1;
        for(const auto& dir : dirn) {
            int i_ = i + dir[0], j_ = j + dir[1];
            if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || !grid[i_][j_] || vis[i_][j_]) continue;
            vis[i_][j_] = true;
            ans += solve(i_, j_, grid);
        }

        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        vis.assign(m, v<bool> (n, false));

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    vis[i][j] = true;
                    res = max(res, solve(i, j, grid));
                }
            }
        }

        return res;
    }
};
