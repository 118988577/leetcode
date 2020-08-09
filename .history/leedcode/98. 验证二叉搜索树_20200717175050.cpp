/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树

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
#include<stdlib.h>
#include<stack>
using namespace std;
class Solution {
public:
//递归版
    // bool isValidBST(TreeNode* root) {
    //     if(root == nullptr)
    //         return true;
    //     TreeNode *leftMax = root->left;
    //     TreeNode *rightMin = root->right;
    //     if(leftMax != nullptr){
    //         while(leftMax->right!=nullptr){
    //             leftMax = leftMax->right;
    //         }
    //     }       
    //     if(rightMin!=nullptr){
    //         while(rightMin->left!=nullptr){
    //             rightMin = rightMin->left;
    //         }
    //     }
    //     if(leftMax!=nullptr && leftMax->val >= root->val || rightMin!=nullptr&&rightMin->val <= root->val)
    //         return false;
    //     return isValidBST(root->left) && isValidBST(root->right);
    // }
//中序遍历
    bool isValidBST(TreeNode* root) {    
        if(root == nullptr){
            return true;
        }
        stack<TreeNode *> nodeStack;
        int lastValue = INT_MIN;
        while(!nodeStack.empty() || root!=nullptr){
            while(root!=nullptr){
                nodeStack.push(root);
                root = root->left;

            }
            root = nodeStack.top();
            nodeStack.pop();
            if(root->val <= lastValue){
                return false;
            }
            lastValue = root->val;
            root = root->right;
        }
        return true;
    }
};