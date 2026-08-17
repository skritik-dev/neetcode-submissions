class Solution {
    typedef pair<int, int> pii;

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pii> cars;

        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort descending based on the position, and it's easier to maintain the fleet if we move from last car

        sort(cars.rbegin(), cars.rend());

        // Time at which the fleet ahead of me is moving
        double prev_t = (double) (target - cars[0].first) / cars[0].second;

        int fleets = 1;
        for(int i = 1; i < n; i++) {
            // Time at which the current fleet is moving
            double curr_t = (double) (target - cars[i].first) / cars[i].second;

            // If I'm moving slower that the fleet ahead of me, then I will never merge into them, else I would 
            if(curr_t > prev_t) {
                fleets++;
                prev_t = curr_t;
            }
        }

        return fleets;
    }
};
