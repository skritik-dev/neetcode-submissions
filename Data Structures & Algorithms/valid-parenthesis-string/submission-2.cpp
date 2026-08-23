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
            if(left.top() > both.top()) return false;
            left.pop();
            both.pop();
        }

        return left.empty();
    }
};
