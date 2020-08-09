/*

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include<vector>
#include <algorithm>
#include<set>
using namespace std;
class Solution {
public:
    set<vector<int>> ans;
    void backtrace(vector<int>& nums,vector<int> &cur,int start){
        if(start == nums.size()){
            ans.insert(cur);
            return;
        }
        for (int i = start; i < nums.size();i++){
            cur.push_back(nums[i]);
            backtrace(nums,cur,start + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())
            return {};
        sort(nums.begin(),nums.end());
        vector<int> current;
        backtrace(nums,current,0);
        vector<vector<int>> res;
        for (set<vector<int>>::iterator it = ans.begin(); it != ans.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};