/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (69.69%)
 * Likes:    500
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 105.1K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为一个单链表。
 * 
 * 
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
using namespace std;
class Solution {
public:
    // vector<TreeNode*> nodes;
    // void dfs(TreeNode* root){
    //     if(root == nullptr)
    //         return;
    //     nodes.push_back(root);
    //     dfs(root->left);
    //     dfs(root->right);
    // }
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        // dfs(root);

        // TreeNode* pre;
        // TreeNode* cur;
        // for(int i = 1;i < nodes.size();i++){
        //     pre = nodes[i-1];
        //     cur = nodes[i];
        //     pre->left = nullptr;
        //     pre->right = cur;
        // }
        TreeNode* preNode;
        TreeNode* cur = root;
        TreeNode* next;
        while(cur!=nullptr){
            if(cur->left!=nullptr){
                //找到左子树最右叶子节点
                next = cur->left;
                preNode = next;
                while(preNode->right!=nullptr){
                    preNode = preNode->right;
                }
                preNode->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->rightl
        }
    }
};
// @lc code=end

