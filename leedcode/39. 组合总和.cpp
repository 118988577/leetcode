/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
            [
            [7],
            [2,2,3]
            ]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
            [
              [2,2,2,2],
              [2,3,3],
              [3,5]
            ]
*/
#include<vector>
#include <algorithm>
#include<set>
#include<numeric>
using namespace std;

class Solution {
    vector<vector<int>> ans;
public:

    void combination(int start,vector<int>& candidates, vector<int> cur,int target){
        int sum = accumulate(cur.begin(),cur.end(),0);
        if(sum == target){
            // sort(cur.begin(),cur.end());
            // if(ans.find(cur)==ans.end()){
            //     ans.insert(cur);
            // }
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size();i++)
        {
            if(sum + candidates[i] > target)
                continue;
            cur.push_back(candidates[i]);
            combination(i,candidates,cur,target);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        combination(0,candidates,current,target);
        return ans;
    }
};