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
    //用first表示下一个要填的位置，则[0，first-1]是已经填的数，[first,n]是要填的位置，对于每个first位置，都可以用[first,n]中任何一个数去填，利用交换两个数
    //完成填写工作，每选择一个数
    //就是一种排列方式，基于此的选择进行下一个数的填写，当待填的位置达到len时，表示每个位置都填写了，此时，达到一种排列情况。在回溯时需要撤销上面数的选择，进行
    //另一种情况填写。
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