/*给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/
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
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> ans;
        stack<TreeNode *> firststack;
        stack<TreeNode *> secondstack;
        firstQueue.push(root);
        while(!firststack.empty()||!secondstack.empty()){
            if(!firststack.empty()){
                vector<int> current;
                while(!firststack.empty()){
                    TreeNode *temp = firststack.top();
                    firststack.pop();
                    if(temp!=nullptr){
                        current.push_back(temp->val);
                        if(temp->left!=nullptr)
                            secondstack.push(temp->left);
                        if(temp->right!=nullptr)
                            secondstack.push(temp->right);
                    }
                }
                ans.push_back(current);
            }
            if(!secondstack.empty()){
                vector<int> current;
                while(!secondstack.empty()){
                    TreeNode *temp = secondstack.top();
                    secondstack.pop();
                    if(temp!=nullptr){
                        current.push_back(temp->val);
                            if(temp->right!=nullptr)
                            firststack.push(temp->right);
                        if(temp->left!=nullptr)
                            firststack.push(temp->left);
  
                    }
                }
                ans.push_back(current);
            }
        }
        return ans;
    }
};