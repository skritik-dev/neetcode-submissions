class Solution {
    vector<int> dir[4] = {
        {-1, 0}, 
        {0, -1},
        {1, 0}, 
        {0, 1}
    };

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int> (n, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        while(!pq.empty()) {
            int pathMax = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            pq.pop();

            if(i == n - 1 && j == n - 1) return pathMax;

            for(const auto& it : dir) {
                int i_ = i + it[0], j_ = j + it[1];
                if(i_ < 0 || i_ >= n || j_ < 0 || j_ >= n || vis[i_][j_]) continue;
                pq.push({max(pathMax, grid[i_][j_]), i_, j_});
                vis[i_][j_] = true;
            }
        }

        return -1;
    }
};
