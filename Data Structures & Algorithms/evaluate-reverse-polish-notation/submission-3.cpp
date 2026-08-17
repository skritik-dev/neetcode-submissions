class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        auto isNumber = [&](const string& str) {
            int sign = 1;
            int num = 0;
            int start = 0;

            // Handle negative number
            if (str[0] == '-') {
                sign = -1;
                start = 1;
            }

            // "-" alone is an operator, not a number
            if (str.size() == 1 && sign == -1)
                return -201;

            for (int i = start; i < str.size(); i++) {
                char ch = str[i];

                if (ch >= '0' && ch <= '9') {
                    num = num * 10 + (ch - '0');
                } else {
                    return -201;
                }
            }

            return sign * num;
        };

        for(const string& token : tokens) {
            int num = isNumber(token);

            // A valid number will always lie in this range [-200, 200]
            if(num >= -200 && num <= 200) {
                s.push(num);
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if(token == "+") s.push(a + b);
                else if(token == "-") s.push(a - b);
                else if(token == "*") s.push(a * b);
                else {
                    if(b == 0) s.push(0);
                    else s.push(a / b);
                }
            }
        }

        return s.top();
    }
};