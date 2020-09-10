/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (56.66%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 23.6K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。
 * 
 * 示例:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * 说明:
 * 
 * 
 * 数组仅可以在 update 函数下进行修改。
 * 你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class NumArray {
public:
    vector<int> tree;
    int N;
    NumArray(vector<int>& nums) {
        N = nums.size();
        if(N > 0){
            tree.resize(2*N);
            buildTree(nums);
        }

    }
    void buildTree(vector<int> nums){
        for (int i = N, j = 0; i < 2 * N;i++,j++){
            tree[i] = nums[j];
        }
        for (int i = N -1; i >0;i--){
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    void update(int i, int val) {
        int pos = i;
        pos += N;
        tree[pos] = val;
        while(pos>0){
            int left = pos;
            int right = pos;
            if(pos%2 == 0){
                right += 1;
            }else{
                left -= 1;
            }
            tree[pos / 2] = tree[left] + tree[right];
            pos /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int l = i;
        int r = j;
        l += N;
        r += N;
        int sum = 0;
        while(l<=r){
            if(l%2 == 1){
                sum += tree[l];
                l++;
            }

            if(r%2==0){
                sum += tree[r];
                r--;
            }

            l /= 2;
            r /= 2;
        }
        return sum;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

