/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 *
 * https://leetcode-cn.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (36.00%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 39.8K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1, 5, 1, 1, 6, 4]
 * 输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
 * 
 * 示例 2:
 * 
 * 输入: nums = [1, 3, 2, 2, 3, 1]
 * 输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
 * 
 * 说明:
 * 你可以假设所有输入都会得到有效的结果。
 * 
 * 进阶:
 * 你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty())
            return;
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(),midptr,nums.end());

        int mid = *midptr;
        int i = 0, j = 0, k = nums.size() - 1;
        while(j < k){
            if(nums[j] > mid){
                swap(nums[j],nums[k]);
                k--;
            }else if(nums[j] < mid){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(nums.size()%2)
            midptr++;
        vector<int> temp1(nums.begin(),midptr);
        vector<int> temp2(midptr,nums.end());
        for (int i = 0; i < temp1.size();i++){
            nums[2 * i] = temp1[temp1.size() - 1 -i];

        }
        for (int i = 0; i < temp2.size();i++){
            nums[2 * i + 1] = temp2[temp2.size() - 1-i];
        }
    }
};
// @lc code=end

