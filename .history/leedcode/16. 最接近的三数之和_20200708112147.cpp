/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 

*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diffValue = __INT_MAX__;
        int ans = 0;
        for (int first = 0; first < nums.size();first++){
            int newTarget = target - nums[first];
            int second = first + 1, third = nums.size() - 1;
            while( second < third){
                if(abs(newTarget - nums[second] - nums[third]) < diffValue){
                    diffValue = abs(newTarget - nums[second] - nums[third]);
                    ans = nums[first] + nums[second] + nums[third];
                }
                if(newTarget - nums[second] - nums[third] > 0){
                    second++;
                }else if(newTarget - nums[second] - nums[third] < 0){
                    third--;
                }else{
                    return target;
                }
            }
        }
        return ans;
    }
};