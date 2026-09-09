class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        int total = 0;
        vector<int> indeg(26, -1);

        // Life saver step
        for(const auto& word : words) {
            for(char ch : word) {
                if(indeg[ch - 'a'] == -1) {
                    indeg[ch - 'a'] = 0;
                    total++;
                }
            }
        }

        unordered_map<char, unordered_set<char>> adj;

        for(int i = 0; i < n - 1; i++) {
            bool hasEdge = false;
            int n1 = words[i].size(), n2 = words[i + 1].size();
            for(int j = 0; j < n1 && j < n2; j++) {
                if(words[i][j] != words[i + 1][j]) {
                    char u = words[i][j], v = words[i + 1][j];
                    
                    if(!adj[u].count(v)) {
                        adj[u].insert(v);
                        indeg[v - 'a']++;
                    }
                    
                    hasEdge = true;
                    break;
                }
            }

            // Check if the word is not a prefix
            if(n1 > n2 && !hasEdge) return "";
        }

        queue<char> q;

        for(int i = 0; i < 26; i++) {
            if(indeg[i] == 0) {
                q.push('a' + i);
            }
        }

        string res = "";
        while(!q.empty()) {
            char u = q.front(); q.pop();
            --total;
            res += u;

            for(const auto& v : adj[u]) {
                --indeg[v - 'a'];
                if(!indeg[v - 'a']) {
                    q.push(v);
                }
            }
        }

        // Cycle detection
        return (!total)? res : "";
    }
};
