/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.38%)
 * Likes:    678
 * Dislikes: 0
 * Total Accepted:    81.9K
 * Total Submissions: 122.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
class Solution {
public:
    //采用归并排序
    ListNode* mergerSort(ListNode* first,ListNode* second){

         //对两个已有序的链表进行合并
         ListNode *frontNode = new ListNode(-1);
         ListNode *curNode = frontNode;
         while(first != nullptr&&second != nullptr){
             if(first->val < second->val){
                 curNode->next = first;
                 first = first->next;
             }else{
                curNode->next = second;
                second = second->next;
             }
            curNode = curNode->next;
         }
        curNode->next = first == nullptr? second:first;
         return frontNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        //对链表进行切割,切割点为slow
        ListNode *fast = head->next;
        ListNode *slow = head;
        ListNode* pmid;
        while(fast!=nullptr&& fast->next!= nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        pmid = slow->next;
        slow->next = nullptr;
        return mergerSort(sortList(head), sortList(pmid));
    }
};
// @lc code=end

