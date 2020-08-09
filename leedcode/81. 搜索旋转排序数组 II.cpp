/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

*/
#include<vector>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<int>& nums, int left,int right,int target){

        if(left > right)
            return false;
        int mid = mid = (left + right) / 2;
        if(nums[mid] == target ||nums[left] == target || nums[right] == target )
            return true;
        if(nums[left] < nums[mid]){
            if(nums[mid] > target && target > nums[left]){
                return binarySearch(nums,left+1,mid - 1,target);
            }else{
                return binarySearch(nums,mid + 1,right - 1,target);
            }
        }else if(nums[mid] < nums[right]){
            if(nums[mid] < target && target < nums[right]){
                return binarySearch(nums,mid + 1,right -1,target);
            }else{
                return binarySearch(nums,left + 1,mid -1,target);
            }
        }else{
            return binarySearch(nums, left + 1, mid - 1, target) || binarySearch(nums,mid+ 1,right - 1,target);
        }
    }
    bool search(vector<int>& nums, int target) {
        bool ans = false;
        if(nums.empty())
            return ans;
        return binarySearch(nums,0,nums.size() - 1,target);
    }
};