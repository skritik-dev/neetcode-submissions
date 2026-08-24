class Solution {
    typedef pair<int, int> pii;

public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), q = queries.size();

        vector<pii> indexes(q);
        for(int i = 0; i < q; i++) indexes[i] = {queries[i], i};
        sort(indexes.begin(), indexes.end());

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); 
        });

        vector<int> res(q);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        int j = 0;
        for(int i = 0; i < q; i++) {
            int query = indexes[i].first, idx = indexes[i].second;

            // Deduplication
            if(i > 0 && indexes[i - 1].first == query) {
                int lastIdx = indexes[i - 1].second;
                res[idx] = res[lastIdx];
                continue;
            }

            // Adding candidate intervals
            while(j < n) {
                if(intervals[j][0] <= query) {
                    pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                    j++;
                } else {
                    break;
                }
            }

            // Extracting the answer for the current query
            int ans = -1;
            while(!pq.empty()) {
                auto peek = pq.top();
                if(query <= peek.second) {
                    ans = peek.first;
                    break;
                } else {
                    pq.pop();
                }
            }

            res[idx] = ans;
        }

        return res;
    }
};
