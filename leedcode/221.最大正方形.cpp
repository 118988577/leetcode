/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (42.58%)
 * Likes:    517
 * Dislikes: 0
 * Total Accepted:    67.1K
 * Total Submissions: 157K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0||matrix[0].size() == 0)
            return 0;
        int r = matrix.size();
        int c = matrix[0].size();

        int maxLong = 0;
        int dp[r][c];
        for (int i = 0; i < r;i++)
            for (int j = 0; j < c;j++){
                if(matrix[i][j] == '1'){
                    if(i == 0||j==0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }
                    maxLong = max(maxLong,dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        return maxLong * maxLong;
    }
};
// @lc code=end

