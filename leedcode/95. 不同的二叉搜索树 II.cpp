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
//递归版
    // vector<TreeNode*> generate(int left,int right){
    //     vector<TreeNode *> allTree;
    //     if(left > right){
    //         allTree.push_back(nullptr);
    //         return allTree;
    //     }
    //     for (int i = left; i <= right;i++){
    //         vector<TreeNode *> leftTree = generate(left,i-1);
    //         vector<TreeNode *> rightTree = generate(i+1,right);
    //         for (vector<TreeNode *>::iterator it_left = leftTree.begin(); it_left != leftTree.end();it_left++){
    //             for (vector<TreeNode *>::iterator it_right = rightTree.begin(); it_right != rightTree.end();it_right++){
    //                 TreeNode *node = new TreeNode(i);
    //                 node->left = *it_left;
    //                 node->right = *it_right;
    //                 allTree.push_back(node);
    //             }
    //         }
    //     }
    //     return allTree;
    // }
    // vector<TreeNode*> generateTrees(int n) {
    //     if(n == 0)
    //         return {};
    //     return generate(1,n);
    // }
//动态规划版
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        vector<TreeNode *> pre;
        pre.push_back(nullptr);
        for (int i = 1; i <= n;i++){
            vector<TreeNode *> cur;
            for (vector<TreeNode *>::iterator it = pre.begin(); it != pre.end();it++){
                //1.以i节点作为根节点插入
                TreeNode *root = TreeNode(i);
                root->left = *it;
                cur.push_back(root);
                //作为根节点的右孩子。。。。。右孩子的右孩子插入
                for (int j = 0; j < i;j++){
                    TreeNode root_copy = treeCopy(*it); //复制当前的树
                    TreeNode right = root_copy; //找到要插入右孩子的位置
                    int k = 0;
                    while(k<j){
                        if(right == nullptr)
                            break;
                        right = right->right;
                        k++;
                    }
                    if(right == nullptr)
                        break;
                    TreeNode *temp = right->right;
                    right->right = new TreeNode(i);
                    right->right->left = temp;
                    cur.push_back(root_copy);
                }
            }
            pre = cur;
        }
        return pre;
    }
    private TreeNode treeCopy(TreeNode root) {
        if (root == null) {
            return root;
        }
        TreeNode newRoot = new TreeNode(root.val);
        newRoot.left = treeCopy(root.left);
        newRoot.right = treeCopy(root.right);
        return newRoot;
    }
};