/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        if(N <= 1){
            return;
        }
        int i = N - 2;
        //从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        //在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、尽可能小的大数「大数」
        int k = N - 1;
        if(i >= 0){
            while(k > i && nums[i] >= nums[k]){
                k--;
            }
            //交换
            int temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};