class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> left, both;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                left.push(i);
            } else if(s[i] == '*') {
                both.push(i);
            } else {
                if(!left.empty()) {
                    left.pop();
                } else if(!both.empty()) {
                    both.pop();
                } else {
                    return false;
                }
            }
        }

        while(!left.empty() && !both.empty()) {
            int l = left.top(), b = both.top();
            left.pop();
            both.pop();
            if(l > b) return false;
        }

        return left.empty();
    }
};
