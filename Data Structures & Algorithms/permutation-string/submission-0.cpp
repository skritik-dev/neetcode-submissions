class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();

        if(m > n) return false;

        vector<int> target(26, 0), curr(26, 0);

        auto check = [&]() {
            for(int i = 0; i < 26; i++) {
                if(target[i] != curr[i]) return false;
            }

            return true;
        };  

        for(const char& ch : s1) ++target[ch - 'a'];

        int l = 0;
        for(int r = 0; r < n; r++) {
            ++curr[s2[r] - 'a'];
            
            if(r >= m - 1) {
                if(check()) return true;
                --curr[s2[l++] - 'a'];    
            }
        }

        return false;
    }
};
