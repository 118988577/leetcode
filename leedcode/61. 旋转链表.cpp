/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<queue>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        queue<ListNode *> listNodeQueue;
        if(head == nullptr||head->next == nullptr || k == 0){
            return head;
        }
        int len = 0;
        ListNode *node = head;
        while(node != nullptr){
            listNodeQueue.push(node);
            node = node->next;
            len++;
        }
        int N = k % len;
        for (int i = 0; i <len - N;i++){
            ListNode *temp = listNodeQueue.front();
            listNodeQueue.pop();
            listNodeQueue.push(temp);
        }
        head = listNodeQueue.front();
        node = head;
        listNodeQueue.pop();
        while(listNodeQueue.size()>0){
            node->next = listNodeQueue.front();
            listNodeQueue.pop();
            node = node->next;
        }
        node->next = nullptr;
        return head;
    }
};