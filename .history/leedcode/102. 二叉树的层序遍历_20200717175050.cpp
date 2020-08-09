/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
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
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> firstQueue;
        queue<TreeNode *> secondQueue;
        firstQueue.push(root);
        while(!firstQueue.empty()||!secondQueue.empty()){
            if(!firstQueue.empty()){
                vector<int> current;
                while(!firstQueue.empty()){
                    TreeNode *temp = firstQueue.front();
                    firstQueue.pop();
                    if(temp!=nullptr){
                        current.push_back(temp->val);
                        if(temp->left!=nullptr)
                            secondQueue.push(temp->left);
                        if(temp->right!=nullptr)
                            secondQueue.push(temp->right);
                    }
                }
                ans.push_back(current);
            }
            if(!secondQueue.empty()){
                vector<int> current;
                while(!secondQueue.empty()){
                    TreeNode *temp = secondQueue.front();
                    secondQueue.pop();
                    if(temp!=nullptr){
                        current.push_back(temp->val);
                        if(temp->left!=nullptr)
                            firstQueue.push(temp->left);
                        if(temp->right!=nullptr)
                            firstQueue.push(temp->right);
                    }
                }
                ans.push_back(current);
            }
        }
        return ans;
    }
};