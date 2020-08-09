/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/
#include<vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums,int left,int right,int target){
        if(left > right){
            return -1;
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[left] == target){
            return left;
        }
        if(nums[right] == target){
            return right;
        }
        //左边有序
        if(nums[left] < nums[mid]){
            if(nums[mid] > target && target > nums[left]){
                return binarySearch(nums,left+1,mid - 1,target);
            }else{
                return binarySearch(nums,mid + 1,right - 1,target);
            }
        }else{
            if(nums[mid] < target && target < nums[right]){
                return binarySearch(nums,mid + 1,right - 1,target);
            }else{
                return binarySearch(nums,left + 1,mid - 1,target);
            }
        }
    
    }
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int ans = binarySearch(nums,0,N -1,target);
        return ans;
    }
};