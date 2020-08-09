/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

*/
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
#include<stack>
using namespace std;
class Solution {
public:
//递归版
    // vector<int> ans;
    // void inorderTraversal(TreeNode* subTree){
    //     if(subTree == nullptr)
    //         return;
    //     int value = subTree->val;
    //     inorderTraversal(subTree->left);
    //     ans.push_back(value);
    //     inorderTraversal(subTree->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     inorderTraversal(root);
    //     return ans;
    // }

//迭代版
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> nodeStack;
        TreeNode *node = root;
        while(node || nodeStack.size()){
            while(node){
                nodeStack.push(node);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
    }   
};