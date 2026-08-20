class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0)? -1 : 1;
        x = abs(x);

        long long rev = 0;

        while(x) {
            int dig = x % 10;
            x /= 10;
            rev = rev * 10 + dig; 
        }

        rev = rev * sign;

        return (rev <= INT_MAX && rev >= INT_MIN)? rev : 0;
    }
};
