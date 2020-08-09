/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
        [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
        ]
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;

    void reback(vector<int> &nums,vector<int> cur){
        if(nums.empty()){
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size();i++){
            int value = nums[i];
            cur.push_back(value);
            nums.erase(nums.begin() + i);
            reback(nums,cur);
            cur.pop_back();
            nums.insert(nums.begin() + i, value);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        reback(nums,current);
        return ans;
    }
};

