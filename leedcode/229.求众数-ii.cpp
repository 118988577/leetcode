/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (43.34%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    19.4K
 * Total Submissions: 44.5K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: [3]
 * 
 * 示例 2:
 * 
 * 输入: [1,1,1,3,3,2,2,2]
 * 输出: [1,2]
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<int> ans;
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;
        for(int num:nums){
            if(num == cand1){
                count1++;
                continue;
            }
            if(num == cand2){
                count2++;
                continue;
            }
            if(count1 == 0){
                cand1 = num;
                count1 = 1;
                continue;
            }
            if(count2 == 0){
                cand2 = num;
                count2 = 1;
                continue;
            }
            count1--;
            count2--;
        }
        count1 = 0;
        count2 = 0;
        for(int num:nums){
            if(num == cand1){
                count1++;
                continue;
            }
            if(num == cand2){
                count2++;
                continue;
            }
        }
        if(count1 > nums.size() /3)
            ans.push_back(cand1);
        if(count2 > nums.size())
            ans.push_back(cand2);
        return ans;
    }
};
// @lc code=end

