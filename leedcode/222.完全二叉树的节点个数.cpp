/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (71.09%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    29.6K
 * Total Submissions: 41.4K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给出一个完全二叉树，求出该树的节点个数。
 * 
 * 说明：
 * 
 * 
 * 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 * 
 * 示例:
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * 输出: 6
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
#include<queue>
using namespace std;
class Solution {
public:

    
    int countNodes(TreeNode* root) {
        int ans = 0;
        if(root == nullptr)
            return 0;
        queue<TreeNode *> nodes;
        nodes.push(root);
        ans++;
        while(!nodes.empty()){
            TreeNode *temp = nodes.front();
            nodes.pop();
            if(temp->left!=nullptr){
                nodes.push(temp->left);
                ans++;
            }
            if(temp->right!=nullptr){
                nodes.push(temp->right);
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

