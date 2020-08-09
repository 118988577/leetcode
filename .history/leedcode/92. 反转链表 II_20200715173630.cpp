/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
。*/
#include<stack>
using namespace std;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr)
            return head;
        ListNode *pre = head;
        ListNode *node = head;
        int count = 0;
        stack<ListNode *>nodeStack;
        while(count < m){
            count++;
            pre = node;
            node = node->next;
        }
        while(count < n){
            nodeStack.push(node);
            pre = node;
            node = node->next;
        }
        while(!nodeStack.empty()){
            ListNode *temp = nodeStack.top();
            pre->next = temp;
            pre = temp;
            nodeStack.POP();
        }
        pre->next = node;
        return head;
    }
};