class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;

        int totalSeats = 0;
        for (char c : corridor)
            if (c == 'S')
                totalSeats++;

        if (totalSeats == 0 || totalSeats % 2)
            return 0;

        long long ans = 1;
        int seats = 0;
        int plants = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seats++;

                // Beginning of a new pair (except the first pair)
                if (seats > 2 && seats % 2 == 1) {
                    ans = (ans * (plants + 1)) % MOD;
                    plants = 0;
                }
            } else {
                // Count plants after completing a pair
                if (seats >= 2 && seats % 2 == 0)
                    plants++;
            }
        }

        return ans;
    }
};