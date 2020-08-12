/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (66.28%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    149K
 * Total Submissions: 224.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  };
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> ans;
    //1.递归版
    
    // void dfs(TreeNode* root){
    //     if(root == nullptr)
    //         return;
    //     ans.push_back(root->val);
    //     dfs(root->left);
    //     dfs(root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root == nullptr)
    //         return ans;
    //     dfs(root);
    //     return ans;
    // }
    //2.迭代
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return ans;
        stack<TreNode *> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode *node = nodeStack.pop();
            ans.push_back(node->val);
            if(node->right!=nullptr)
                nodeStack.push(node->right);
            if(node->left!=nullptr)
                nodeStack.push(node->left);
        }
        return ans;
    }
};
// @lc code=end

