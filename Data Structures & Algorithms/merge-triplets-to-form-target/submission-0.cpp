class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = -1, y = -1, z = -1;
        
        for(const auto& it : triplets) {
            if(target[0] >= it[0] && target[1] >= it[1] && target[2] >= it[2]) {
                x = max(x, it[0]);
                y = max(y, it[1]);
                z = max(z, it[2]);
            } 
        }

        return (x == target[0] && y == target[1] && z == target[2]);
    }
};
