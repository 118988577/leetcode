/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.

*/
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
    ListNode* swapPairs(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }
        ListNode* first = head;
        ListNode *second = head->next;
        head = second;
        ListNode *lastNode = nullptr;
        while(first!=nullptr && second !=nullptr){

            ListNode* temp = second->next;
            second->next = first;
            first->next = temp;
            if(lastNode!=nullptr){
                lastNode->next = second;
            }
            lastNode = first;
            first = first->next;
            if(first !=nullptr){
                second = first->next;
            }
            
        }
        return head;
    }
};
