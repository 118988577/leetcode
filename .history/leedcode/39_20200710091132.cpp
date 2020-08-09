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
    set<vector<int>> ans;
public:

    void combination(vector<int>& candidates, vector<int>& cur,int target){
        int sum = accumulate(cur.begin(),cur.end(),0);
        if(sum >= target){
            if(sum == target){
                sort(cur.begin(),cur.end());
                if(ans.find(cur)==ans.end()){
                    ans.insert(cur);
                }
            }
            return;
        }
        for (int i = 0; i < candidates.size();i++){
            cur.push_back(candidates[i]);
            combination(candidates,cur,target);
            if(cur[0] == 2 && cur[1] == 2){
                int test = 0;
               
                test++;
            }
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        combination(candidates,current,target);
        vector<vector<int>> res;
        for (set<vector<int>>::iterator it = ans.begin(); it != ans.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};
int main(){
    Solution test;
    vector<int> example = {1, 2};
    test.combinationSum(example,4);
    return 0;
}