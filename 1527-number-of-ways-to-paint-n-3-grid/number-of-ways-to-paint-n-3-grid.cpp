class Solution {
public:
    int numOfWays(int n) {
        long long mod = 1e9 + 7;

        long long aba = 6;
        long long abc = 6;

        for (int i = 2; i <= n; i++) {
            long long newABA = (3 * aba + 2 * abc) % mod;
            long long newABC = (2 * aba + 2 * abc) % mod;

            aba = newABA;
            abc = newABC;
        }

        return (aba + abc) % mod;
    }
};