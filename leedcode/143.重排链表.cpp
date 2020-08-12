/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (56.14%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 60K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return ;
        vector<ListNode *> ListVector;
        ListNode *next = head;
        while(next!= nullptr){
            ListVector.push_back(next);
            next = next->next;
        }
        ListNode *newList;
        newList = head;
        for (int front = 1, back = ListVector.size() - 1; front <= back;front++,back--){
            if(front < back){
                newList->next = ListVector[back];
                newList = newList->next;
                newList->next = ListVector[front];
                newList = newList->next;
            }else{
                newList->next = ListVector[back];
                newList = newList->next;  
            }
        }
        newList->next = nullptr;
    }
};
// @lc code=end

