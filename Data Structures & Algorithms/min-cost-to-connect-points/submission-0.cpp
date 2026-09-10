class DSU {
    vector<int> par, rank;

public:
    DSU(int n) {
        rank.assign(n, 0);
        par.assign(n, -1);
        for(int i = 0; i < n; i++) par[i] = i;
    }

    int findSet(int u) {
        if(par[u] == u) return u;
        return par[u] = findSet(par[u]);
    }

    bool unionSet(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        if(pu == pv) return false;
        if(rank[pu] < rank[pv]) swap(pu, pv);
        rank[pu] += rank[pv];
        par[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<vector<int>> dist;

        for(int i = 0; i < n; i++) {
            int xi = nums[i][0], yi = nums[i][1];
            for(int j = i + 1; j < n; j++) {
                int xj = nums[j][0], yj = nums[j][1];
                dist.push_back({abs(xi - xj) + abs(yi - yj), i, j});
            }
        }

        sort(dist.begin(), dist.end());

        DSU *dsu = new DSU(n);

        int res = 0, edges = 0;
        for(const auto& it : dist) {
            int wt = it[0], u = it[1], v = it[2];
            if(dsu->unionSet(u, v)) {
                edges++;
                res += wt;
                if(edges == n - 1) break;
            }
        }

        return res;
    }
};