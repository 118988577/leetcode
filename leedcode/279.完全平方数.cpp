/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (57.01%)
 * Likes:    561
 * Dislikes: 0
 * Total Accepted:    80.4K
 * Total Submissions: 139.9K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start
#include <algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        fill(dp,dp + n + 1,INT_MAX);
        dp[0] = 0;
        int sqartIndex = sqrt(n) + 1;
        int sqartNums[sqartIndex];
        for (int i = 1; i < sqartIndex;i++){
            sqartNums[i] = i * i;
        }

        for (int i = 0; i <= n;i++){
            for (int j = 1; j < sqartIndex;j++){
                if(i < sqartNums[j])
                    break;
                dp[i] = min(dp[i],dp[i - sqartNums[j]] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

