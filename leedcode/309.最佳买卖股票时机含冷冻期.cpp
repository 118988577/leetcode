/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (57.14%)
 * Likes:    537
 * Dislikes: 0
 * Total Accepted:    55.6K
 * Total Submissions: 97.3K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int N = prices.size();
        int f[N][3];
        //初始条件
        f[0][0] = -prices[0];
        f[0][1] = 0;
        f[0][2] = 0;
        //f[i][0]:表示第i天结束后持有一支股票的累计最大收益
        //f[i][1]:表示第i天结束后没有持有股票，且处于冷冻期
        //f[i][2]:表示第i天结束后没有持有股票，且未处于冷冻期
        for (int i = 1; i < N;i++){
            f[i][0] = max(f[i-1][2] - prices[i],f[i-1][0]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[N-1][1],f[N-1][2]);
    }
};
// @lc code=end

