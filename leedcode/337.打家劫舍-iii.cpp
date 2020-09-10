/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode-cn.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (60.15%)
 * Likes:    571
 * Dislikes: 0
 * Total Accepted:    67K
 * Total Submissions: 111.3K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
 * 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 * 
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
 * 
 * 示例 2:
 * 
 * 输入: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<map>
using namespace std;
class Solution {
public:
    map<TreeNode *, int> f;
    map<TreeNode *, int> g;

    void dfs(TreeNode* node){
        if(node==nullptr)
            return ;
        dfs(node->left);
        dfs(node->right);
        if(node->left&&node->left){
            f[node] = g[node->left] + g[node->right] + node->val;
            g[node] = max(f[node->left],g[node->left]) + max(f[node->right],g[node->right]);
        }else if(node->left){
            f[node] = g[node->left] + node->val;
            g[node] = max(f[node->left], g[node->left]);
        }else if(node->right){
            f[node] = g[node->right] + node->val;
            g[node] = max(f[node->right],g[node->right]);
        }else{
            f[node] = node->val;
            g[node] = 0;
        }

    }
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        dfs(root);
        return max(f[root],g[root]);
    }
};
// @lc code=end

