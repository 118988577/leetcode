/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (64.11%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    61K
 * Total Submissions: 95K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root== nullptr)
            return ans;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            vector<TreeNode *> nodes;
            while(!nodeQueue.empty()){
                nodes.push_back(nodeQueue.front());
                nodeQueue.pop();
            }
            TreeNode *temp = nodes[nodes.size() - 1];
            ans.push_back(temp->val);
            for(TreeNode* node: nodes){
                if(node->left != nullptr)
                    nodeQueue.push(node->left);
                if(node->right != nullptr)
                    nodeQueue.push(node->right);
            }
        }
        return ans;
    }
};
// @lc code=end

