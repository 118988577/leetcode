/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (36.68%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 104.2K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
    static  bool cmp(int a,int b){
        string str1 = to_string(a);
        string str2 = to_string(b);
        string newStr1,newStr2;
        newStr1 = str1 + str2;
        newStr2 = str2 + str1;
        return newStr1 > newStr2;

    }
public:

    string largestNumber(vector<int>& nums) {
        if(nums.empty())
            return "";
        string ans;
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0)
            return "0";
        for(int value:nums){
            ans += to_string(value);
        }
        return ans;
    }
};
// @lc code=end

