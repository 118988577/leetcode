class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];

        if(n == 1){
            return 1;
        }else if(n == 2){
            return 2;
        }else if(n == 3){
            return 3;
        }else{
            dp[n] = 0;
            dp[n - 1] = 1;
            dp[n - 2] = 2;
            for (int i = n - 3; i >= 0;i--){
                dp[i] = dp[i + 1] + dp[i + 2];
            }
        }

        return dp[0];
    }
};