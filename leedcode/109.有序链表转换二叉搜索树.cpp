/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (73.20%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 49.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
class Solution {
public:
    vector<int> nodeValue;
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* node = head;
        while(node!=nullptr){
            nodeValue.push_back(node->val);
            node = node->next;
        }
       return BST(nodeValue,0,nodeValue.size()-1);
    }
    TreeNode* BST(vector<int>& nums,int left,int right){
        if(left > right){
            return nullptr;
        }
        int midIndex = left + (right - left)/2;
        TreeNode* temp = new TreeNode(nums[midIndex]);
        temp->left = BST(nums,left,midIndex -1);
        temp->right = BST(nums,midIndex +1,right);
        return temp;
    }
};
// @lc code=end

