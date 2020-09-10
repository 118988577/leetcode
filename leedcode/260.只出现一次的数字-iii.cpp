/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 *
 * https://leetcode-cn.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (73.26%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 37.9K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
 * 
 * 示例 :
 * 
 * 输入: [1,2,1,3,2,5]
 * 输出: [3,5]
 * 
 * 注意：
 * 
 * 
 * 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
 * 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.empty())
            return {};
        map<int, int> count;
        for(int x :nums){
            if(count.count(x) == 0){
                count[x] = 1;
            }else{
                count[x]++;
            }
        }
        vector<int> ans;
        for (map<int, int>::iterator it = count.begin(); it != count.end();it++){
            if(it->second == 1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end

