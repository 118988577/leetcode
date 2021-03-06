/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
            [
            [1, 7],
            [1, 2, 5],
            [2, 6],
            [1, 1, 6]
            ]
*/
#include<vector>
#include <algorithm>
#include<set>
#include<numeric>
using namespace std;
class Solution {
public:
    set<vector<int>> ans;
    void combination(int start,vector<int>& candidates,vector<int> cur, int target){
        int sum = accumulate(cur.begin(),cur.end(),0);
        if(sum == target){

            if(ans.find(cur) == ans.end()){
                ans.insert(cur);
            }
            return;
        }
        for (int i = start; i < candidates.size();i++){
            if(sum + candidates[i] > target)
                continue;
            cur.push_back(candidates[i]);
            combination(i + 1, candidates, cur, target);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        combination(0,candidates, current, target);
        vector<vector<int>> res;
        for (set<vector<int>>::iterator it = ans.begin(); it != ans.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};