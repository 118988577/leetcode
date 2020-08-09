/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/
#include <vector>
using namespace std;
class Solution {
public:
//遍历每个可以跳的位置，维护一个可以跳的最远距离，如果最远距离大于最后一个位置，就可以跳到
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int maxRight = 0;
        for (int i = 0; i < N;i++){
            if(i <= maxRight){
                maxRight = max(maxRight, i + nums[i]);
            }
            if (maxRight >= N -1)
                return true;
        }
        return false;
    }
};