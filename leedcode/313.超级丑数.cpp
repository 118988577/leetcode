/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 *
 * https://leetcode-cn.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (63.49%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 16.4K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * 编写一段程序来查找第 n 个超级丑数。
 * 
 * 超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 12, primes = [2,7,13,19]
 * 输出: 32 
 * 解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12
 * 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
 * 
 * 说明:
 * 
 * 
 * 1 是任何给定 primes 的超级丑数。
 * 给定 primes 中的数字以升序排列。
 * 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000 。
 * 第 n 个超级丑数确保在 32 位有符整数范围内。
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<set>
#include<queue>
using namespace std;
class Solution {
public:
    class Ugly{
        public:
        vector<long long> nums;
        Ugly(int n, vector<int>& primes ){
            set<long long> geted;
            priority_queue<long long, vector<long long>, greater<long long>> q;
            long long count = 0;
            q.push(1);
            long long k = primes.size();
            while(count < n){
                long long value = q.top();
                q.pop();
                for (int i = 0; i < k;i++){
                    if(geted.count(value*primes[i]) == 0){
                        geted.insert(value*primes[i]);
                        q.push(value * primes[i]);
                    }
                }
                nums.push_back(value);
                count++;
            }
        }
    };

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1)
            return 1;
        Ugly ans = Ugly(n,primes);
        return ans.nums[n - 1];
    }
};
// @lc code=end

