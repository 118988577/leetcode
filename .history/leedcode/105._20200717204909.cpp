/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
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
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* BT(vector<int>& preorder, int preleft,int preright,vector<int>& inorder,int inleft,int inright){
        if(preleft>preright||inleft>inright)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preleft]);
        int value = root->val;
        int preorderlen = 0;
        for (int i = inleft; i <= inright;i++)
        {
            if(inorder[i]!=value){
                preorderlen++;
                break;
            }
        }
        root->left = BT(preorder, preleft + 1, preleft + preorderlen, inorder, inleft, inleft + preorderlen - 1);
        root->right = BT(preorder,preleft + 1 + preorderlen,preright,inorder,inleft + preorderlen+1,inright);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(preorder.empty())
        //     return nullptr;
        return BT(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
int main(){
    Solution test;
    vector<int> preorder = {1, 2};
     vector<int> inorder = {1, 2};   
    TreeNode* root = test.buildTree(preorder,inorder);
    return 0;
}