/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/
#include<vector>
#include<set>
#include <algorithm>
using namespace std;
class Solution {
public:
    set<vector<int>> ans;
    void reback(vector<int> &nums,int first,int len){
        if(first == len){
            sort(nums.begin(),nums.end());
            ans.insert(nums);
            return;
        }
        for (int i = first; i < len;i++){
            swap(nums[i],nums[first]);
            reback(nums,first + 1,len);
            swap(nums[i],nums[first]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        reback(nums,0,nums.size());
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res;
        for (set<vector<int>>::iterator it = ans.begin(); it != ans.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};