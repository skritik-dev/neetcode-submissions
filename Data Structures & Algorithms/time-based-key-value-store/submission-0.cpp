class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string val, int ts) {
        mp[key].push_back({ts, val});
    }
    
    string get(string key, int ts) {
        if (!mp.count(key)) return "";

        auto& v = mp[key];
        auto it = upper_bound(v.begin(), v.end(), ts, [](int timestamp, const pair<int, string>& p) {
            return timestamp < p.first;
        });

        return (it == v.begin()) ? "" : (it - 1)->second;
    }
};
