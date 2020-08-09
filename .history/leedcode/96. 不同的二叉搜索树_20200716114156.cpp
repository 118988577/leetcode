/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
#include<vector>

class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        int dp[n + 1] ={0,0,0};
        //边界
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n;i++){
            //求出dp[i]表示有1.。。i为节点组成的二叉树有多少种
            for (int j = 1; j <= i;j++)
                dp[i] += dp[j-1] *  dp[i - j];
        }
        return dp[n];
    }
};