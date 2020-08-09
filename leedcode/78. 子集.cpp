/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void reback(vector<int> &nums, vector<int> &cur,int start, int len){
        if(start == len){
            ans.push_back(cur);
            return;
        }
        ans.push_back(cur);
        for (int i = start; i < nums.size();i++){
            int temp = nums[i];
           // nums.erase(nums.begin() + i);
            cur.push_back(temp);
            reback(nums, cur, i + 1,len);
            cur.pop_back();
            //nums.insert(nums.begin() + i,temp);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int> current;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        reback(nums,current,0,len);
        return ans;
    }
};