/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (53.25%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    32.3K
 * Total Submissions: 60.4K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start
#include<set>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        set<long long > geted;
        priority_queue<long long,vector<long long>,greater<long long>> q;
        vector<long long> dp;
        long long count = 0;

        q.push(1);
        while(count < n){
            long long value = q.top();
            q.pop();
            if(geted.count(value * 2) == 0){
                q.push(value * 2);
                geted.insert(value * 2);
            }
            if(geted.count(value * 3) == 0){
                q.push(value * 3);
                geted.insert(value * 3);
            }
            if(geted.count(value * 5) == 0){
                q.push(value * 5);
                geted.insert(value * 5);
            }
            dp.push_back(value);
            count++;
        }
        return dp[n-1];
    }
};

// @lc code=end

