/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (40.01%)
 * Likes:    701
 * Dislikes: 0
 * Total Accepted:    86K
 * Total Submissions: 214.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int N = nums.size();
        int ans = nums[0], maxf = nums[0],minf = nums[0];

        for (int i = 1; i < N;i++){
            int mx = maxf, mi = minf;
            maxf = max(mx*nums[i], max(nums[i],mi*nums[i]));
            minf = min(mx*nums[i], min(nums[i],mi*nums[i]));
            ans = max(
                ans,maxf);
        }
        return ans;
    }
};
// @lc code=end

