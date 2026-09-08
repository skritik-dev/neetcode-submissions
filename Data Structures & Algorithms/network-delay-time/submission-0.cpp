class Solution {
    typedef pair<int, int> pii;
    #define ff first
    #define ss second

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n + 1);

        for(const auto& it : times) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
        }
        
        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int t_curr = pq.top().ff, u = pq.top().ss;
            pq.pop();

            if(t_curr > time[u]) continue;

            for(const auto& it : adj[u]) {
                int v = it.ff, t_uv = it.ss;

                if(time[v] > t_curr + t_uv) {
                    time[v] = t_curr + t_uv;
                    pq.push({time[v], v});
                }
            }
        }

        // Maximum of the minimum time is the answer!

        int res = 0;
        for(int i = 1; i <= n; i++) {
            res = max(res, time[i]);
        }

        return (res == INT_MAX)? -1 : res;
    }
};
