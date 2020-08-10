/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (66.68%)
 * Likes:    560
 * Dislikes: 0
 * Total Accepted:    98.9K
 * Total Submissions: 148.2K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 
 * 
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
// int minValue = INT_MAX;
    // void dfs(vector<vector<int>>& triangle,int i,int j,int sum){
    //     if(i >= triangle.size()){
    //         if(sum < minValue){
    //             minValue = sum;
    //         }
    //         return;
    //     }

    //     dfs(triangle,i+1,j,sum+triangle[i][j]);
    //     if(j +1 < triangle[i+1].size())
    //         dfs(triangle,i+1,j+1,sum+triangle[i][j]);
    // } 
    int minimumTotal(vector<vector<int>>& triangle) {
        // if(triangle.empty())
        //     return 0;
        // dfs(triangle,0,0,0);
        int H = triangle.size();
        int L = triangle[H - 1].size();
        vector<vector<int>> dp(H, vector<int>(H));
        if(H == 0)
            return 0;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < H;i++){
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size() - 1;j++)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        }
            return *min_element(dp[H-1].begin(),dp[H-1].end());
    }
};
// int main(){
//     Solution test;
//     vector<vector<int>> example ={{2},{3,4},{6,5,7},{4,1,8,3}};
//     test.minimumTotal(example);
//     return 0;
// }
// @lc code=end

