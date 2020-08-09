/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void reback(vector<int> &nums,vector<int> &cur,int start,int k ){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        for (int i =start; i < nums.size();i++){
            int temp = nums[i];
            cur.push_back(temp);
            nums.erase(nums.begin() + i);
            reback(nums,cur,i,k);
            nums.insert(nums.begin() + i,temp);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n;i++){
            nums.push_back(i);
        }
        vector<int> current;
        reback(nums,current,0,k);
        return ans;
    }
};