/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 *
 * https://leetcode-cn.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (53.21%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 22.8K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
 * 
 * 示例 1:
 * 
 * 输入: [0,1,2,4,5,7]
 * 输出: ["0->2","4->5","7"]
 * 解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
 * 
 * 示例 2:
 * 
 * 输入: [0,2,3,4,6,8,9]
 * 输出: ["0","2->4","6","8->9"]
 * 解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
 * 
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<string> ans;
        string curSection;
        long long pre = nums[0], cur = nums[0];
        curSection += to_string(nums[0]);
        for (int i = 1; i < nums.size();i++){
            cur = nums[i];
            if(cur - pre == 1){
                pre = cur;
                continue;
            }else{
                if(to_string(pre) != curSection){
                    curSection += "->" + to_string(pre);
                }
                
                ans.push_back(curSection);
                curSection.clear();
                curSection = to_string(cur);
                pre = cur;
            }
        }
        if(to_string(pre) !=  curSection ){
            curSection += "->" + to_string(pre);
        }
        ans.push_back(curSection);
        return ans;
    }
};
// @lc code=end

