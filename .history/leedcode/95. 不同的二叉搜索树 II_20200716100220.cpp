/*

给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

 

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
*/

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
    vector<TreeNode*> generate(int left,int right){
        vector<TreeNode *> allTree;
        if(left > right){
            allTree.push_back(nullptr);
            return;
        }
        for (int i = left; i <= right;i++){
            vector<TreeNode *> left = generate(left,i-1);
            vector<TreeNode *> right = generate(i+1,right);
            for (vector<TreeNode *>::iterator it = left.begin(); it != left.end();it++){
                
            }
        }
        vector<TreeNode *> left = generate(1, );
    }
    vector<TreeNode*> generateTrees(int n) {
        
    }
};