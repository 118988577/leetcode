/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/
#include <vector>
using namespace std;
class Solution {
public:

    int searchLeft(vector<int> &nums,int target){
        if(nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }

    int searchRight(vector<int> &nums,int target){
        if(nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> ans;
        ans.push_back(searchLeft(nums,target));
        ans.push_back(searchRight(nums,target));
        return ans;
    }
};