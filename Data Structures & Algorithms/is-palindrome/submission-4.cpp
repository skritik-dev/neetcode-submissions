class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char ch : s) {
            if(isalnum(ch)) {
                if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    temp += (char) tolower(ch);
                else 
                    temp += ch;
            }
        }

        int n = temp.size();

        for(int i = 0; i < n / 2; i++) {
            if(temp[i] != temp[n - i - 1]) return false;
        }

        return true;
    }
};
