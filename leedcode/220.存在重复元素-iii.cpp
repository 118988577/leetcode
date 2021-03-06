/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 *
 * https://leetcode-cn.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (26.37%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 84.1K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * 在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j
 * 的差的绝对值也小于等于 ķ 。
 * 
 * 如果存在则返回 true，不存在返回 false。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3, t = 0
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1, t = 2
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
 * 输出: false
 * 
 */

// @lc code=start
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> data;
        for (int i = 0; i < nums.size();i++){
            set<int>::iterator it = data.upper_bound(nums[i]);
            if(!data.empty() && *it - nums[i] <= t)
                return true;
            it = data.lower_bound(nums[i]);

            if(!data.empty()&&  nums[i] - *it <= t )
                return true;
            data.insert(nums[i]);
            if(data.size() > k){
                data.erase(nums[i-k]);
            }
        }
        return false;
    }
};
// @lc code=end

