/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.51%)
 * Likes:    502
 * Dislikes: 0
 * Total Accepted:    104K
 * Total Submissions: 168.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */

// @lc code=start
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
static bool cmp(pair<int,int> x,pair<int,int> y){
        return x.second > y.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size();i++){
            if(numMap.count(nums[i]) == 0){
                numMap[nums[i]] = 1;
            }else{
                numMap[nums[i]]++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> ans;
        for(auto x:numMap){
            if(ans.size() < k){
                ans.push(x.first);
            }else {
                if(numMap[ans.top()] < x.second){
                ans.pop();
                ans.push(x.first);
                }
            }
        }
        vector<int> res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }
};
// @lc code=end

