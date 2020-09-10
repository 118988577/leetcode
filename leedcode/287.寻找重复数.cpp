/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (65.79%)
 * Likes:    835
 * Dislikes: 0
 * Total Accepted:    92.3K
 * Total Submissions: 140.3K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        // for (int i = 0; i < nums.size();i++){
        //     for (int j = i+1; j < nums.size();j++){
        //         if(nums[i] == nums[j])
        //             ans = nums[i];
        //     }
        // }
        // return ans;
        // sort(nums.begin(),nums.end());
        // for (int i = 0; i < nums.size() - 1;i++){
        //     if(nums[i] == nums[i+1])
        //         ans = nums[i];
        // }
        // return ans;
        //快慢指针
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[fast];
        //寻找相遇点
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        //Slow从起点出发,fast从相遇点出发，寻找环的入口
        slow = 0;
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

