class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0) return 0;

        vector<int>dp(n+1,0);
        dp[0] = 1;

        dp[1] = (s[0] == '0') ? 0 : 1;

        for(int i=2; i<=n;i++){
            string oneDigit = s.substr(i-1,1);
            if(oneDigit != "0"){
                dp[i] += dp[i-1];
            }

            string twoDigit = s.substr(i-2,2);
            if(twoDigit >= "10" && twoDigit <= "26"){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};
