class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> moves = {
            {4, 6},    // 0
            {6, 8},    // 1
            {7, 9},    // 2
            {4, 8},    // 3
            {0, 3, 9}, // 4
            {},        // 5
            {0, 1, 7}, // 6
            {2, 6},    // 7
            {1, 3},    // 8
            {2, 4}     // 9
        };

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = 0;
                for (int move : moves[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][move]) % MOD;
                }
            }
        }

        int result = 0;
        for (int digit = 0; digit < 10; ++digit) {
            result = (result + dp[n][digit]) % MOD;
        }

        return result;
    }
};
