/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.61%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 38.1K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    set<set<int>> ans;
    int k_val, n_val;
    void backtracking(set<int>& current,int count,int sum,int  start){

        if(count > k_val){
            if(sum == n_val){
                if(ans.find(current) == ans.end()){
                    ans.insert(current);
                }
            }
            return;
        }
        if(sum >= n_val)
            return;
        for (int value = start; value <= 9;value++){
            if(current.find(value) == current.end()){
                current.insert(value);
                backtracking(current,count+1,sum + value,start+1);
                current.erase(value);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n == 0){
            return {};
        }
        k_val = k;
        n_val = n;
        set<int> current;
        backtracking(current,1,0,1);
        vector<vector<int>> res;
        for(set<int> nums:ans){
            vector<int> temp;
            for (int v : nums){
                temp.push_back(v);
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

