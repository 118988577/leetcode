/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
using namespace std;
class Solution {

public:
    TreeNode* root ;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()){
            return nullptr;
        }
        root = buildTree(inorder,0,inorder.size() -1,postorder,0,postorder.size()-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, int inleft,int inright,vector<int>& postorder,int postleft,int postright){
        TreeNode* temp;
        if(inleft > inright){
            return nullptr;
        }
        int rootValue = postorder[postright];
        temp = new TreeNode(rootValue);
        int index = inleft;
        for(;index <= inright;index++){
            if(inorder[index] == rootValue){
                break;
            }
        }

        temp->left = buildTree(inorder,inleft,index-1,postorder,postleft,postleft + index - inleft -1);
        temp->right = buildTree(inorder,index + 1,inright,postorder,postleft + index - inleft,postright - 1);
        return temp;
    }
};
// @lc code=end

