class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        stack<int> s;
        vector<int> res;
        res.reserve(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && temp[s.top()] <= temp[i]) {
                s.pop();
            }

            int val = (s.empty())? 0 : s.top() - i;
            res.push_back(val);
            s.push(i);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};